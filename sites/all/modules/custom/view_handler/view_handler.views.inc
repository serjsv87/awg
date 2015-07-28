<?php
function view_handler_views_data() {
  $data = array();
  $data['node']['myhandler'] = array(
    'title' => t('test handler title'),
    'help' => t('Obana rabotaet!'),
    'field' => array(
      'handler' => 'view_handler_string_node_custom',
      'click sortable' => true
    ),
    'sort' => array(
      'handler' => 'views_handler_sort'
    ),
    /*
    'filter' => array(
      'handler' => 'view_handler_string_node_custom'
    )*/
  );
  return $data;
}