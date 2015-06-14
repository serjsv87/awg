<?php
/**
 * Created by PhpStorm.
 * User: ggrenuy
 * Date: 09.06.15
 * Time: 16:38
 */

function subBartik_theme_registry_alter(&$theme_registry) {
  $theme_path = path_to_theme();

  // Checkboxes.
  if (isset($theme_registry['checkbox'])) {
    $theme_registry['checkbox']['type'] = 'theme';
    $theme_registry['checkbox']['theme path'] = $theme_path;
    $theme_registry['checkbox']['template'] = $theme_path . '/templates/field--type-checkbox';
    unset($theme_registry['checkbox']['function']);
  }
}