<?php
class IndexModel extends Model {
    public function checkUser(){

        $login = $_POST['login'];
        $password = $_POST['password'];// md5 need

        //$sql = "SELECT * FROM users WHERE username = :login AND password_hash = :password";
        $sql = "SELECT id, username FROM users WHERE username = :login AND password_hash = :password";

        $stmt = $this->db->prepare($sql);
        $stmt->bindValue(":login", $login, PDO::PARAM_STR);
        $stmt->bindValue(":password", $password, PDO::PARAM_STR);
        $stmt->execute();

        $res = $stmt->fetch(PDO::FETCH_ASSOC);


        if(!empty($res)){
            $_SESSION['user'] = $_POST['login'];
            $_SESSION['user_id'] = $res['id'];
            $_SESSION['cart'] = array();  // для корзины
            header("Location: /cabinet");
            //echo "ok";
            return true;
        }else{
            return false;
        }
    }
}