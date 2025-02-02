<?php
class IndexController extends Controller{

    private $pageTpl = '/app/views/main.tpl.php';
    public function __construct()
    {
        $this->model = new IndexModel();
        $this->view = new View();
    }

    public function index(){
        $this->pageData['title'] = "Вход в личный кабинет";


        //print_r($_POST);

        if(!empty($_POST)){
            if(!$this->login()){
                $this->pageData['error'] = "Неправильный логин или пароль";
                echo"error";
            }
        }

        $this->view->render($this->pageTpl, $this->pageData);
    }

    public function login(){
        if(!$this->model->checkUser()){
            return false;
        }
        return true;
    }
    public function order(){ //функция-заглушка!!
        header("Location: /app/views/order_confirmation.tpl.php");
        exit();
    }
}