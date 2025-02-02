<?php

class ProductsModel extends Model {

    public function getCategories() {
        $sql = "SELECT
                categories.id as categoriesID,
                categories.name as categoriesName
                FROM categories";
        $result = array();
        $stmt = $this->db->prepare($sql);
        $stmt->execute();
        while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
            $result[$row['categoriesID']] = $row;
        }
        return $result;
    }

    public function getProducts() {
        $sql = "SELECT
                products.id as productID,
                products.name as productName,
                products.description as productDescription,
                products.price as productPrice,
                category_id as productCategory
                FROM products";
        $result = array();
        $stmt = $this->db->prepare($sql);
        $stmt->execute();
        while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
            $result[$row['productCategory']][] = $row;
        }
        return $result;
    }
}