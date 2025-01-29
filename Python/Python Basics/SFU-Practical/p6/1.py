import datetime

diary = {'понедельник': {
 'утро': ['погулять с собакой'],
 'день': [],
'вечер': ['погулять с собакой']
 },
 'вторник': {
 'утро': ['погулять с собакой'],
 'день': [],
'вечер': ['погулять с собакой']
 },
 'среда': {
 'утро': ['погулять с собакой'],
 'день': [],
'вечер': ['погулять с собакой']
 },
 'четверг': {
 'утро': ['погулять с собакой'],
 'день': [],
'вечер': ['погулять с собакой']
 },
 'пятница': {
 'утро': ['заехать в шиномонтаж', 'помыть машину'],
 'день': [],
'вечер': ['поход в театр', 'ужин в кафе']
 },
 'суббота': {
 'утро': [],
'день': [],
'вечер': []
 },
 'воскресенье': {
 'утро': [],
'день': [],
'вечер': []
 }}

#1
def first():
	del diary['суббота']
	del diary['воскресенье']
	diary[('суббота', 'воскресенье')] = ['посадить цветы на даче']

#2
def second():
	diary['вторник']['утро'].append('поход к зубному')

#3
def third():
	diary['пятница']['вечер'][0] = 'поход в кино'

#4
def fourth():
	diary['четверг']['утро'].remove('погулять с собакой')
	diary['четверг']['вечер'].remove('погулять с собакой')

#5
def fifth():

	print(diary['пятница']['утро'][1])

#6
def sixth():

	del diary['понедельник']
	try:
		diary['понедельник']
	except Exception as e:
		print(e)

# 7. Функция вывода списка дел на интересующий пользователя день недели

def show_tasks(day):
    tasks = diary.get(day, None)
    if tasks is None:
        print("Такого дня недели не существует.")
        return
    
    if all(len(tasks[time]) == 0 for time in tasks):
        print("Свободный день.")
        return
    
    for time, tasks_list in tasks.items():
        if tasks_list:
            print(f"{time.capitalize()}: {', '.join(tasks_list)}.")
        else:
            print(f"{time.capitalize()}: нет дел.")

# 8. Функция для вывода списка дел на сегодня
def show_today_tasks():
    today = datetime.datetime.now().strftime('%A').lower()  # Получаем текущий день недели на английском
    days_in_russian = {
        'monday': 'понедельник',
        'tuesday': 'вторник',
        'wednesday': 'среда',
        'thursday': 'четверг',
        'friday': 'пятница',
        'saturday': 'суббота',
        'sunday': 'воскресенье'
    }
    
    today_russian = days_in_russian[today]
    print(f"Список дел на сегодня ({today_russian}):")
    show_tasks(today_russian)
    
# 9. Функция для сброса расписания на неделю
def reset_schedule():
    for day in diary.keys():
        diary[day] = {'утро': [], 'день': [], 'вечер': []}

# 10. Функция для заполнения словаря делами
def fill_tasks():
    while True:
        day = input("Введите день недели (или 'выход' для завершения): ").strip().lower()
        if day == "выход":
            break
        
        if day not in diary:
            print("Такого дня недели не существует. Попробуйте снова.")
            continue
        
        time_of_day = input("Введите время суток (утро, день, вечер): ").strip().lower()
        
        if time_of_day not in ['утро', 'день', 'вечер']:
            print("Некорректное время суток. Попробуйте снова.")
            continue
        
        task = input("Введите дело (или оставьте пустым для завершения): ").strip()
        
        if task:
            diary[day][time_of_day].append(task)
            print(f"Дело '{task}' добавлено в {day} на {time_of_day}.")
        else:
            print("Дело не добавлено.")

show_today_tasks()  # Выводим список дел на сегодня
reset_schedule()  # Сбрасываем расписание
fill_tasks()  # Заполняем расписание новыми делами