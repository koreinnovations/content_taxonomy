<?php

/**
 * @file
 * Plugin to provide a relationship handler for terms from content taxonomy field.
 */

/**
 * Implementation of specially named hook_ctools_relationships().
 */
function content_taxonomy_terms_from_field_ctools_relationships() {
  $args['terms_from_field'] = array(
      'title' => t('Terms from field'),
      'keyword' => 'content_taxonomy',
      'description' => t('Adds taxonomy terms from a content taxonomy field.'),
      'required context' => new ctools_context_required(t('Node'), 'node'),
      'context' => 'content_taxonomy_terms_from_field_context',
      'settings form' => 'content_taxonomy_terms_from_field_settings_form',
  );
  return $args;
}

/**
 * Return a new context based on an existing context.
 */
function content_taxonomy_terms_from_field_context($context, $conf) {
  // Check if we have a node in this context.
  if (!empty($context->data)) {
    // Check if we have data for the field selected in relationship settings.
    if (isset($context->data->{$conf['field_name']}) && is_array($context->data->{$conf['field_name']})) {
      $data = new stdClass;
      $data->operator = $conf['operator'];
      $data->value = array();
      foreach ($context->data->{$conf['field_name']} as $delta => $item) {
        if (!empty($item['value'])) {
          $data->value[] = $item['value'];
        }
      }
      if (!empty($data->value)) {
        return ctools_context_create('terms', $data);
      }
    }
  }

  // If unset it wants a generic, unfilled context, which is just NULL.
  return ctools_context_create_empty('terms', NULL);
}

/**
 * Settings form for the relationship.
 */
function content_taxonomy_terms_from_field_settings_form($conf) {
  $options = array();
  foreach (content_fields () as $field_name => $field) {
    if ($field['type'] == 'content_taxonomy') {
      $options[$field_name] = t($field['widget']['label']);
    }
  }

  $form['field_name'] = array(
      '#title' => t('Content taxonomy field'),
      '#type' => 'select',
      '#options' => $options,
      '#default_value' => $conf['field_name'],
      '#description' => t('Enter the content field this taxonomy relationship is attached to.'),
      '#prefix' => '<div class="clear-block">',
      '#suffix' => '</div>',
  );

  $form['operator'] = array(
      '#title' => t('Operator'),
      '#type' => 'radios',
      '#options' => array('or' => t('OR'), 'and' => t('AND')),
      '#default_value' => isset($conf['operator']) ? $conf['operator'] : 'or',
      '#description' => t('Select OR operator to separate multiple terms by +, or AND operator to separate them by ,'),
      '#prefix' => '<div class="clear-block">',
      '#suffix' => '</div>',
  );

  return $form;
}