<?php
/**
 * Custom filter handler for views, that handles DATETIME
 */
class view_handler_handler_filter_field_count extends views_handler_filter_numeric {
  function operators() {
    $operators = parent::operators();
    // We won't be using regex in our example
    unset($operators['regular_expression']);
 
    return $operators;
  }
 
  function field_count() {
    $this->real_field = 'title';
 
    $field = "$this->table_alias.$this->real_field";
    return "LENGTH($field)-LENGTH(REPLACE($field,' ',''))+1";
  }
 
  // Override the op_between function
  // adding our field count function as parameter
  function op_between($field) {
    $field_count = $this->field_count();
 
    $min = $this->value['min'];
    $max = $this->value['max'];
 
    if ($this->operator == 'between') {
      $this->query->add_where_expression($this->options['group'], "$field_count BETWEEN $min AND $max");
    }
    else {
      $this->query->add_where_expression($this->options['group'], "($field_count <= $min) OR ($field_count >= $max)");
    }
  }
 
  // Override the op_simple function
  // adding our field count function as parameter
  function op_simple($field) {
    $field_count = $this->field_count();
 
    $value = $this->value['value'];
 
    $this->query->add_where_expression($this->options['group'], "$field_count $this->operator $value");
  }
}