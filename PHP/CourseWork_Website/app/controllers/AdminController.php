<?php

class AdminController extends Controller {

    private $pageTpl = "/app/views/admin.tpl.php";
    public function __construct()
    {
        $this->model = new AdminModel();
        $this->view = new View();
    }

    public function index(){

        if(!isset($_SESSION['user'])){
            header("Location: /");
            exit(); // gpt
        }

        $validateAdmin = $this->model->validateAdmin();

        if (!$validateAdmin) {
            // Если пользователь не админ, то на главную todo доделать 403 forbidden
            header("Location: /cabinet");
            exit();
        }

        $this->pageData['title'] = "Админ-панель";

        //$this->pageData['validatedAdmin'] = $validateAdmin; // old
        $this->pageData['userList'] = $this->model->getUsers();

        $this->view->render($this->pageTpl,$this->pageData);
    }
}