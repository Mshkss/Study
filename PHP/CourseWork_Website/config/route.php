<?php

/*
 * Класс маршрутизации
 * урл http://164.215.68.12/
 * урл http://164.215.68.12/cabinet
 * урл http://164.215.68.12/admin
 * урл http://164.215.68.12/products
 * урл http://164.215.68.12/cart
 */

class routing{
    public static function buildRoute(){

        /*контроллер и action по умолчанию*/
        $controllerName = "IndexController";
        $modelName = "IndexModel";
        $action = "index";

        $route = explode("/",parse_url( $_SERVER['REQUEST_URI'],PHP_URL_PATH)); // разделение URL на массив

        $i = count($route)-1;
        //echo $i;
        //print_r($route);
        while ($i>0){
            if($route[$i]!= ''){
                if(is_file(CONTROLLER_PATH. ucfirst($route[$i]). "Controller.php")){
                    $controllerName = ucfirst($route[$i]). "Controller";
                    $modelName = ucfirst($route[$i]). "Model";
                    break;
                }
                else{
                    $action = $route[$i];
                }
            }
            $i--;
        }

        require_once CONTROLLER_PATH . $controllerName . ".php"; // IndexController.php
        require_once MODEL_PATH . $modelName . ".php"; // IndexModel.php

        $controller = new $controllerName();
        $controller->$action(); // $controller->index();
    }
    public function errorPage403(){
        echo "403 Forbidden";
    }
    public function errorPage404(){
        echo "404 Page Not Found";
    }
}