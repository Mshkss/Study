<?php
class AdminModel extends model{

    public function validateAdmin(){ //проверка что пользователь является админом

        $isAdminID = $_SESSION['user_id'];
        //echo $isAdminID;

        $sql = "SELECT id FROM users WHERE id = :user_id AND isadmin = 1";

        $stmt = $this->db->prepare($sql);
        $stmt->bindValue(':user_id', $isAdminID, PDO::PARAM_INT);
        $stmt->execute();


        $result = $stmt->fetch(PDO::FETCH_ASSOC);

        if ($result) {
            return true; // Пользователь является администратором
        } else {
            return false; // Пользователь не является администратором

        }
    }

    public function getUsers(){

        $sql = "select * from users";

        $stmt = $this->db->prepare($sql);
        $stmt->execute();
        $result = array();
        while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
            $result[$row['id']] = $row;
        }
        return $result;
    }



}