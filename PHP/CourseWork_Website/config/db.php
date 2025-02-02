<?php

class DB{

    const USER = "*";
    const PASS = "*";
    const DB = "*";
    const HOST = "*";

    public static function connToDB(){
        $user = self::USER;
        $pass = self::PASS;
        $host = self::HOST;
        $db = self::DB;

        $conn = new PDO("mysql:dbname=$db;host=$host; charset=UTF8", $user,$pass);
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        return $conn;
    }

}