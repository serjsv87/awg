<?php
class view_handler_string_node_custom extends views_handler_field {

  function construct() {
    parent::construct();

  }
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  function render($values) {
    return 'Privet!';
  }
}
?>