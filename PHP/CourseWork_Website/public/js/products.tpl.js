// document.addEventListener('DOMContentLoaded', function() {
//     const products = document.querySelectorAll('.product');
//
//     products.forEach(product => {
//         const buyButton = product.querySelector('.buy-button');
//         const quantityControls = product.querySelector('.quantity-controls');
//         const quantitySpan = quantityControls.querySelector('.quantity');
//         const increaseButton = quantityControls.querySelector('.increase');
//         const decreaseButton = quantityControls.querySelector('.decrease');
//
//         buyButton.addEventListener('click', function() {
//             buyButton.style.display = 'none';
//             quantityControls.style.display = 'flex';
//         });
//
//         increaseButton.addEventListener('click', function() {
//             let quantity = parseInt(quantitySpan.textContent);
//             quantity++;
//             quantitySpan.textContent = `${quantity} шт`;
//         });
//
//         decreaseButton.addEventListener('click', function() {
//             let quantity = parseInt(quantitySpan.textContent);
//             if (quantity > 1) {
//                 quantity--;
//                 quantitySpan.textContent = `${quantity} шт`;
//             } else {
//                 quantityControls.style.display = 'none';
//                 buyButton.style.display = 'block';
//             }
//         });
//     });
// });

document.addEventListener('DOMContentLoaded', function() {
    const products = document.querySelectorAll('.product');

    products.forEach(product => {
        const buyButton = product.querySelector('.buy-button');
        const quantityControls = product.querySelector('.quantity-controls');
        const quantitySpan = quantityControls.querySelector('.quantity');
        const increaseButton = quantityControls.querySelector('.increase');
        const decreaseButton = quantityControls.querySelector('.decrease');

        buyButton.addEventListener('click', function() {
            buyButton.style.display = 'none';
            quantityControls.style.display = 'flex';
            addToCart(product.dataset.productId, 1); // Добавление товара в корзину с количеством 1
            quantitySpan.textContent = `1 шт`;
        });

        increaseButton.addEventListener('click', function() {
            let quantity = parseInt(quantitySpan.textContent);
            quantity++;
            quantitySpan.textContent = `${quantity} шт`;
            updateCart(product.dataset.productId, quantity); // Обновление количества товара в корзине
        });

        decreaseButton.addEventListener('click', function() {
            let quantity = parseInt(quantitySpan.textContent);
            if (quantity > 1) {
                quantity--;
                quantitySpan.textContent = `${quantity} шт`;
                updateCart(product.dataset.productId, quantity); // Обновление количества товара в корзине
            } else {
                quantityControls.style.display = 'none';
                buyButton.style.display = 'block';
                removeFromCart(product.dataset.productId); // Удаление товара из корзины
            }
        });
    });

    function addToCart(productId, quantity) {
        fetch('/cart/addToCart', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            },
            body: `product_id=${productId}&quantity=${quantity}`
        })
            .then(response => response.json())
            .then(data => {
                if (data.status === 'success') {
                    console.log('Product added to cart');
                } else {
                    console.error('Failed to add product to cart:', data.message);
                }
            })
            .catch(error => console.error('Error:', error));
    }

    function updateCart(productId, quantity) {
        fetch('/cart/updateCart', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            },
            body: `product_id=${productId}&quantity=${quantity}`
        })
            .then(response => response.json())
            .then(data => {
                if (data.status === 'success') {
                    console.log('Cart updated');
                } else {
                    console.error('Failed to update cart:', data.message);
                }
            })
            .catch(error => console.error('Error:', error));
    }

    function removeFromCart(productId) {
        fetch('/cart/removeFromCart', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            },
            body: `product_id=${productId}`
        })
            .then(response => response.json())
            .then(data => {
                if (data.status === 'success') {
                    console.log('Product removed from cart');
                } else {
                    console.error('Failed to remove product from cart:', data.message);
                }
            })
            .catch(error => console.error('Error:', error));
    }
});