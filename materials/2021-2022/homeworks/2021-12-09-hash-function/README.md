Имплементирайте хEш функция, която да дава по-добър резултат от ползваната в час:
- резултатите трябва да са равномерно разпределени в интервала от възможни стойности, които може да върне
- функцията трябва да има ниска сложност за да работи бързо
- глобални променливи са забранени
- при подадена еднаква входна стойност резултатът трябва да е винаги еднакъв
- по-проста имплементация ще оперира върху символите на стринг. По-сложна имплементация ще оперира върху байтовете от област с памет за по-генерално приложение


В прикачения архив има код, с който можете да тествате хеширащите си функции. Тестващата функция очаква размер на таблицата, име на файл, от който да чете ключове и указател към хешираща функция. В main.c има пример с 3 прости варианта за функция. input1.txt и input2.txt съдържат тестови ключове под формата на стрингове. Можете да експериментирате с различни хеширащи функции, размери на таблицата и стойности на ключове. Специална награда за този, който напише функция с най-малък брой колизии при размер 4000 и файл input1.txt.

https://www.cpp.edu/~ftang/courses/CS240/lectures/hashing.htm
