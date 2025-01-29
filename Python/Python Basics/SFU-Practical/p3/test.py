import copy
# fruits = ['Яблоко', 'мандарин', 'Апельсин', 'виноград']
# sorted_fruits = sorted(fruits, key=lambda x: x.lower())
# # print(sorted_fruits)


#
my_list = [1, 2, 3,[4,5]]
# my_tuple = tuple(my_list)
	


mylistcopy = copy.deepcopy(my_list)

my_list[-1].append(6)


print(mylistcopy)

# my_list.deepcopy()