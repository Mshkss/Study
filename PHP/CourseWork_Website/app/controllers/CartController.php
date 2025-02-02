<?php


class CartController extends Controller {


    private $pageTpl = "/app/views/cart.tpl.php";

    public function __construct()
    {
        $this->model = new CartModel();
        $this->view = new View();
    }

    public function index()
    {

        if (!isset($_SESSION['user'])) {
            header("Location: /");
            exit();
        }

        // Передача данных о корзине в представление
      //  $cartContents = $this->model->getCartContents();
        //$this->pageData['cartContents'] = $cartContents; //тупа для примера, код взят из ...


        //$this->pageData['cart'] = $_SESSION['cart']; старый отладочный вывод для корзины


        $cart = $_SESSION['cart'] ?? [];
        $products = $this->model->getProductsByIds(array_keys($cart));





        $this->pageData['cart'] = $cart;
        $this->pageData['products'] = $products;

        $this->pageData['title'] = "Корзина покупок";
        $this->view->render($this->pageTpl,$this->pageData);
    }

    public function addToCart() {
        if (!isset($_SESSION['user'])) {
            echo json_encode(['status' => 'error', 'message' => 'User not logged in']);
            return;
        }

        $productId = $_POST['product_id'];

        $quantity = $_POST['quantity'];

        if (!isset($_SESSION['cart'])) {
            $_SESSION['cart'] = [];
        }

        if (isset($_SESSION['cart'][$productId])) {
            $_SESSION['cart'][$productId] += $quantity;
        } else {
            $_SESSION['cart'][$productId] = $quantity;
        }

        echo json_encode(['status' => 'success', 'cart' => $_SESSION['cart']]);
    }
    public function updateCart() {
        if (!isset($_SESSION['user'])) {
            echo json_encode(['status' => 'error', 'message' => 'User not logged in']);
            return;
        }

        $productId = $_POST['product_id'];
        $quantity = $_POST['quantity'];

        if (isset($_SESSION['cart'][$productId])) {
            $_SESSION['cart'][$productId] = $quantity;
        }

        echo json_encode(['status' => 'success']);
    }

    public function removeFromCart() {
        if (!isset($_SESSION['user'])) {
            echo json_encode(['status' => 'error', 'message' => 'User not logged in']);
            return;
        }

        $productId = $_POST['product_id'];

        if (isset($_SESSION['cart'][$productId])) {
            unset($_SESSION['cart'][$productId]);
        }

        echo json_encode(['status' => 'success']);
    }

    public function viewCart() { //получает из бд данные о товаре
        if (!isset($_SESSION['user'])) {
            header("Location: /");
            exit();
        }

//        $cart = $_SESSION['cart'] ?? [];
//        $products = $this->model->getProductsByIds(array_keys($cart));

//        $this->pageData['cart'] = $cart;
//        $this->pageData['products'] = $products;
//
//        $this->pageData['title'] = "Корзина";
//
//        $this->view->render($this->pageTpl, $this->pageData);
    }
    public function placeOrder()
    {
        if (!isset($_SESSION['user'])) {
            echo json_encode(['status' => 'error', 'message' => 'User not logged in']);
            return;
        }

        $userId = $_SESSION['user_id'];
        $cart = isset($_SESSION['cart']) ? $_SESSION['cart'] : [];
        $products = $this->model->getProductsByIds(array_keys($cart));

        if (empty($cart)) {
            echo json_encode(['status' => 'error', 'message' => 'Cart is empty']);
            return;
        }

        $totalPrice = 0;
        foreach ($cart as $productId => $quantity) {
            $totalPrice += $products[$productId]['productPrice'] * $quantity;
        }

        $orderId = $this->model->createOrder($userId, $totalPrice);

        if ($orderId) {
            foreach ($cart as $productId => $quantity) {
                $this->model->createOrderDetails($orderId, $productId, $quantity, $products[$productId]['productPrice']);
            }

            // Очистка корзины после оформления заказа
            unset($_SESSION['cart']);

            echo json_encode(['status' => 'success']);
        } else {
            echo json_encode(['status' => 'error', 'message' => 'Failed to create order']);
        }
    }

}