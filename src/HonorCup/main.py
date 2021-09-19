# -*- coding: utf-8 -*-
"""
Created on 10/22/2020 12:09 PM

@author: Ruslan V. Akhpashev
"""



# download geckodriver (https://github.com/mozilla/geckodriver/releases)


from selenium import webdriver
#pip install selenium

import time

#first of all, get a token

TOKEN = 'https://quiz.honorcup.ru/app/?id=8984&sign=a6b2463b835b1b010590b8ff827ae88f'

#open a browser (FireFox)
browser = webdriver.Firefox(executable_path='geckodriver.exe')
browser.get(TOKEN)
time.sleep(4)

#click battle_button
battle_button = browser.find_element_by_class_name('about__buttons')
print(battle_button)
battle_button.click()
time.sleep(4)

# -------> ТУТ МЫ ВИДИМ ТЕМАТИКИ ОЛИМПИАДЫ

#choose a category and theme
category = browser.find_elements_by_class_name('slider__item')
category[0].click()

#choose a theme
theme = browser.find_elements_by_class_name('profile__theme')
theme[1].click()

# inspect -> pick a button -> copy -> XPath
categories_play_button = browser.find_element_by_xpath('/html/body/app/div[1]/nomination/div/div/div[2]/div[3]/div[2]/div/div/div[2]/div')#('button-group-2x')
categories_play_button.click()
time.sleep(25)

#
#parsing a question
round_question = browser.find_element_by_class_name('game__question-text')
print("Question: ",round_question.text)

#parsing possible answers
round_answers = browser.find_elements_by_class_name('game__answer')
print("Answers: ", round_answers[0].text)
print(round_answers[1].text)
print(round_answers[2].text)
print(round_answers[3].text)
round_answers[0].click()