<?php

class CabinetController extends Controller{

    private $pageTpl = "/app/views/cabinet.tpl.php";

    public function __construct()
    {
    $this->model = new CabinetModel();
    $this->view = new View();
    }

    public function index(){

        //echo $_SESSION['user'];

        if(!isset($_SESSION['user'])){
            header("Location: /");
            exit(); // gpt
        }

        $this->pageData['title'] = "Личный кабинет";

        $ordersCount = $this->model->getOrdersCount(); // количество заказов
        $this->pageData['ordersCount'] = $ordersCount;

        $orders = $this->model->getOrders(); // заказы из бд
        $this->pageData['orders'] = $orders;

        $name = $this->model->userNameCabinet();// todo!
        $this->pageData['userNameCabinet'] = $name;

        $this->view->render($this->pageTpl,$this->pageData);


    }

    public function logout(){
        session_destroy();
        header("Location: /");
    }

}