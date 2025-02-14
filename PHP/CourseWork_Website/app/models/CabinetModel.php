<?php

class CabinetModel extends Model {

    public function getOrdersCount(){
        $sql = "select COUNT(*) FROM orders";
        $stmt = $this->db->prepare($sql);
        $stmt->execute();
        $res = $stmt->fetchColumn();

        return $res;

    }

    public function getOrders(){ // todo: по юзерам отфильтровать, но возможно что это все пишется для админки и придется выводить кто и что заказывал

        $userId = $_SESSION['user_id'];

        $sql = "SELECT
                orders.id as id,
                order_date as date,
                order_status as status,
                total_price
                FROM orders
                WHERE user_id = :user_id
        ";

        $stmt = $this->db->prepare($sql);
        $stmt->bindValue(':user_id', $userId, PDO::PARAM_INT);
        $stmt->execute();


        $result = array();
        while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
            $result[$row['id']] = $row;
        }
        return $result;
    }
    public function userNameCabinet(){

        $username = $_SESSION['user'];
        return $username;

    }
}