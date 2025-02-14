document.addEventListener('DOMContentLoaded', function() {
    const removeButtons = document.querySelectorAll('.remove-button');
    const placeOrderButton = document.getElementById('place-order-button');

    removeButtons.forEach(button => {
        button.addEventListener('click', function() {
            const productId = button.dataset.productId;
            removeFromCart(productId);
        });
    });

    if (placeOrderButton) {
        placeOrderButton.addEventListener('click', function() {
            placeOrder();
        });
    }

    function removeFromCart(productId) {
        fetch('/cart/remove', {
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
                    location.reload(); // Перезагрузка страницы для обновления корзины
                } else {
                    console.error('Failed to remove product from cart:', data.message);
                }
            })
            .catch(error => console.error('Error:', error));
    }

    function placeOrder() {
        fetch('/cart/placeOrder', { // /cart/placeOrder
            method: 'POST',
            headers: {
                'Content-Type': 'application/x-www-form-urlencoded'
            }
        })
            .then(response => response.json())
            .then(data => {
                if (data.status === 'success') {
                    console.log('Order placed successfully');
                    location.href = '/order/confirmation'; // Перенаправление на страницу подтверждения заказа
                } else {
                    console.error('Failed to place order:', data.message);
                }
            })
            .catch(error => console.error('Error:', error));
    }
});