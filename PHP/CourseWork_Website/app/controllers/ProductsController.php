<?php

class ProductsController extends Controller{

    private $pageTpl = "/app/views/products.tpl.php";

    public function __construct()
    {
        $this->model = new ProductsModel();
        $this->view = new View();
    }



    public function index(){

        if(!isset($_SESSION['user'])){
            header("Location: /");
            exit();
        }


        $categoriesList = $this->model->getCategories();
        $this->pageData['categories'] = $categoriesList;

        $productList = $this->model->getProducts();
        $this->pageData['products'] =$productList;

        //echo "1";
        $cart = $_SESSION['cart'] ?? [];
        $this->pageData['cart'] = $cart;

        $this->pageData['title'] = "Магазин";
        $this->view->render($this->pageTpl,$this->pageData);
    }


}