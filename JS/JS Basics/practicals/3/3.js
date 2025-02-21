//alert( 'Привет, мир!' );
let arr =[
	{name:"apple", count: 5, price: 70},
	{name:"orange", count: 10, price: 90}
];

let sum = 0;


for(let i = 0; i < arr.length; i++){
sum+=arr[i].count * arr[i].price;
}


console.log("price = ", sum)