# Android Development
## Установка:
### Windows
- Стандартная установка "из коробки" [Android Studio].
#### Работа эмулятора на AMD процессорах:
- https://android-developers.googleblog.com/2018/07/android-emulator-amd-processor-hyper-v.html
### Linux
- Скачать файл с официального сайта [Android Studio].
- Распоковать данный файл, желательно в папку /home/, командой:
```sh
cd /home/
tar xzf android-studio-2020.3.1.24-linux.tar.gz
``` 
- Далее можно запускать Android Studio из папки /android-studio/bin/studio.sh. 
```sh
cd /android-studio/bin
./studio.sh
``` 
- Но для удобства сделайте [.desktop] "иконку", чтобы приложение определялось системой.
#### Эмулятор
- В данный момент проблем не выявил. Если возникнут проблемы, прошу отправить Pull Request.
## Полезные ссылки:
- [Start Android] - хорошие основы по Android и Java.
- [Kotlin] - удобный интерфейс для начального изучения Kotlin (очень удобно работать на примерах). Также есть [github] репозиторий с примерами.
### Android Java
#### Урок 1. Activity Life Cycle (Жизненый цикл приложения)
- [ActivityLifeCycle] - жизненый цикл activity. Довольно подробно и легко объясняется работа activity.

 [Android Studio]: <https://developer.android.com/studio>
 [.desktop]: <https://mymemorylife.wordpress.com/2016/09/23/%D0%BA%D0%B0%D0%BA-%D1%81%D0%BE%D0%B7%D0%B4%D0%B0%D1%82%D1%8C-%D1%8F%D1%80%D0%BB%D1%8B%D0%BA-%D0%B2-ubuntu-%D0%B4%D0%BB%D1%8F-%D0%B7%D0%B0%D0%BF%D1%83%D1%81%D0%BA%D0%B0-sh-shell-%D1%81%D0%BA%D1%80/>
 [Kotlin]: <https://play.kotlinlang.org/byExample/overview>
 [Start Android]: <https://www.youtube.com/channel/UCzE7HcbvyEiS5ea1rVRbPLQ>
 [github]: <https://github.com/Kotlin/kotlin-by-example/tree/master/examples>
 [ActivityLifeCycle]: <http://developer.alexanderklimov.ru/android/theory/lifecycle.php>
