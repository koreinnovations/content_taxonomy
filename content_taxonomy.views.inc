<?php

/**
 * Subclass of views_handler_filter_many_to_one_content
 *
 * provides values for the filters
 * unsets the empty value for non required fields, which is added content_taxonomy_allowed_values
 */
class views_handler_filter_many_to_one_content_taxonomy extends views_handler_filter_many_to_one_content {
  var $content_field;

  function construct() {
    parent::construct();
  }

  function get_value_options() {
    $options = content_taxonomy_allowed_values($this->content_field);
    unset($options['']);
    $this->value_options = $options;
  }
}
