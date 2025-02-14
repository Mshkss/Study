<?php

class CartModel extends Model {

    public function getProductsByIds($productIds) {
        if (empty($productIds)) {
            return [];
        }

        $placeholders = implode(',', array_fill(0, count($productIds), '?'));
        $sql = "SELECT id as productID, name as productName, description as productDescription, price as productPrice
                FROM products
                WHERE id IN ($placeholders)";
        $stmt = $this->db->prepare($sql);
        $stmt->execute($productIds);

        $products = [];
        while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
            $products[$row['productID']] = $row;
        }

        return $products;
    }

    public function createOrder($userId, $totalPrice) {
        $sql = "INSERT INTO orders (user_id, order_status, total_price, order_date) VALUES (:user_id, 'processed', :total_price, NOW())";
        $stmt = $this->db->prepare($sql);
        $stmt->bindValue(':user_id', $userId, PDO::PARAM_INT);
        $stmt->bindValue(':total_price', $totalPrice, PDO::PARAM_STR);
        $stmt->execute();

        if ($stmt->rowCount() > 0) {
            return $this->db->lastInsertId();
        } else {
            return false;
        }
    }

    public function createOrderDetails($orderId, $productId, $quantity, $pricePerItem) {
        $sql = "INSERT INTO order_details (order_id, product_id, quantity, price_per_item) VALUES (:order_id, :product_id, :quantity, :price_per_item)";
        $stmt = $this->db->prepare($sql);
        $stmt->bindValue(':order_id', $orderId, PDO::PARAM_INT);
        $stmt->bindValue(':product_id', $productId, PDO::PARAM_INT);
        $stmt->bindValue(':quantity', $quantity, PDO::PARAM_INT);
        $stmt->bindValue(':price_per_item', $pricePerItem, PDO::PARAM_STR);
        $stmt->execute();

        return $stmt->rowCount() > 0;
    }
}