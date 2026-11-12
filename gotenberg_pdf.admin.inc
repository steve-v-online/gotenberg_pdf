<?php

/**
 * @file
 * Gotenberg PDF settings form and submit action
 */

/**
 * Menu callback - gotenberg_pdf admin settings form
 */
function gotenberg_pdf_admin() {
  $config = config('gotenberg_pdf.settings');

  $form['#config'] = 'gotenberg_pdf.settings';
  $form['gotenberg_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Gotenberg Settings'),
  );
  $form['gotenberg_settings']['gotenberg_host'] = array(
    '#type' => 'textfield',
    '#title' => t('Gotenberg Host'),
    '#description' => t('The Gotenberg host, including protocol and port.'),
    '#default_value' => $config->get('gotenberg_host'),
    '#size' => 30,
  );
  $form['gotenberg_settings']['gotenberg_endpoint'] = array(
    '#type' => 'textfield',
    '#title' => t('Gotenberg Endpoint'),
    '#description' => t('The Gotenberg endpoint for converting URLs to PDF.'),
    '#default_value' => $config->get('gotenberg_endpoint'),
    '#size' => 30,
  );
  $form['gotenberg_settings']['path'] = array(
    '#type' => 'textfield',
    '#title' => t('Path'),
    '#description' => t('The path convert to PDF. Defaults to <strong>node</strong>, but can be set to use the path of another Layout, such as <strong>print</strong>. Note that <strong>pdf</strong> is reserved.'),
    '#default_value' => $config->get('path'),
    '#size' => 30,
  );
  $form['gotenberg_settings']['filename_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('PDF Filename Pattern'),
    '#description' => t('The pattern for the filename of the generated PDF. Use <strong>[node:title]</strong> to include the node title.'),
    '#default_value' => $config->get('filename_pattern'),
    '#size' => 30,
  );
  $form['gotenberg_settings']['filename_tokens'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node'),
    '#dialog' => TRUE,
  );
  $form['gotenberg_settings']['scale'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale'),
    '#default_value' => $config->get('scale'),
    '#size' => 5,
  );
  $form['gotenberg_settings']['single_page'] = array(
    '#type' => 'checkbox',
    '#title' => t('Single Page'),
    '#description' => t('If checked, the PDF will be generated as a single page.'),
    '#default_value' => $config->get('single_page'),
  );
  $form['gotenberg_settings']['margin_top'] = array(
    '#type' => 'textfield',
    '#title' => t('Margin Top'),
    '#default_value' => $config->get('margin_top'),
    '#size' => 8,
  );
  $form['gotenberg_settings']['margin_bottom'] = array(
    '#type' => 'textfield',
    '#title' => t('Margin Bottom'),
    '#default_value' => $config->get('margin_bottom'),
    '#size' => 8,
  );
  $form['gotenberg_settings']['margin_left'] = array(
    '#type' => 'textfield',
    '#title' => t('Margin Left'),
    '#default_value' => $config->get('margin_left'),
    '#size' => 8,
  );
  $form['gotenberg_settings']['margin_right'] = array(
    '#type' => 'textfield',
    '#title' => t('Margin Right'),
    '#default_value' => $config->get('margin_right'),
    '#size' => 8,
  );
  $form['gotenberg_settings']['api_timeout'] = array(
    '#type' => 'textfield',
    '#title' => t('API Timeout (seconds)'),
    '#default_value' => $config->get('api_timeout'),
    '#size' => 5,
  );

  return system_settings_form($form);
}
