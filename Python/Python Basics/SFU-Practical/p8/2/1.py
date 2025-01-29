import requests
from datetime import datetime, timedelta

class Rate:
    def __init__(self, format='value'):
        self.format = format
    
    def allRates(self):  # exchange rates
        r = requests.get("https://www.cbr-xml-daily.ru/daily_json.js")
        return r.json()['Valute']
    
    def curRate(self, Valute, diff=False):  # make format
        response = self.allRates()
        if Valute in response:
            if diff:
                return response[Valute]['Value'] - response[Valute]['Previous']
            if self.format == 'full':
                return response[Valute]
            elif self.format == 'value':
                return response[Valute]['Value']
            elif self.format == 'name_value':
                return f"{response[Valute]['Name']} {response[Valute]['Value']} руб."
        return 'error'
    
    def eur(self, diff=False):
        return self.curRate('EUR', diff)
    
    def usd(self, diff=False):
        return self.curRate('USD', diff)

    def get_currency_info(self, currency_code):
        return self.curRate(currency_code)
    
    def max_currency(self):
        rates = self.allRates()
        max_currency = max(rates.values(), key=lambda x: x['Value'])
        return f"{max_currency['Name']} {max_currency['Value']} руб."
    
    def min_currency(self):
        rates = self.allRates()
        min_currency = min(rates.values(), key=lambda x: x['Value'])
        return f"{min_currency['Name']} {min_currency['Value']} руб."

    def exchange_date_rates(self, date):
        formatted_date = date.strftime('%Y/%m/%d')
        r = requests.get(f"https://www.cbr-xml-daily.ru/archive/{formatted_date}/daily_json.js")
        if r.status_code == 200:
            return r.json()['Valute']
        else:
            return 'Нет данных'

    def usd_over_weeks(self, weeks=1):
        rates = {}
        for i in range(weeks):
            date = datetime.now() - timedelta(weeks=i)
            rate_data = self.exchange_date_rates(date)
            if rate_data != 'Нет данных' and 'USD' in rate_data:
                rates[date.strftime('%Y-%m-%d')] = rate_data['USD']['Value']
            else:
                rates[date.strftime('%Y-%m-%d')] = 'Нет данных'
        return rates

    def currency_over_weeks(self, currency_code, weeks=1):
        rates = {}
        for i in range(weeks*7):
            date = datetime.now() - timedelta(days=i)
            rate_data = self.exchange_date_rates(date)
            if rate_data != 'Нет данных' and currency_code in rate_data:
                rates[date.strftime('%Y-%m-%d')] = rate_data[currency_code]['Value']
            else:
                rates[date.strftime('%Y-%m-%d')] = 'Нет данных'
        return rates

curr = Rate('name_value')
print(curr.allRates())
print(curr.usd())
print(curr.eur(diff=True))
print(curr.get_currency_info('EUR'))
print(curr.max_currency())
print(curr.min_currency())
print(curr.usd_over_weeks(3)) #USD за 2 недели
print(curr.currency_over_weeks('EUR', 3)) # Получение курса произвольной валюты за последние 2 недели

