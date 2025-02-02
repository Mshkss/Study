<?php

session_start();

define("ROOT", $_SERVER['DOCUMENT_ROOT']);
define("CONTROLLER_PATH", ROOT. "/app/controllers/");
define("MODEL_PATH", ROOT. "/app/models/");
define("VIEW_PATH", ROOT. "/app/views/");

require_once("db.php");
require_once("route.php");
require_once CONTROLLER_PATH. 'Controller.php';
require_once MODEL_PATH. 'Model.php';
require_once VIEW_PATH. 'View.php';

Routing::buildRoute();


