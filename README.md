# DC_Motor_Control
# Türkçe
Bu proje, bir DC motorun hız ve yön kontrolünü Arduino ve L293D H-köprü sürücü entegresi ile gerçekleştirmektedir. Projede kullanılan butonlar ve görsel geri bildirim sağlayan LED’ler sayesinde motorun yönü ve hızı kullanıcı tarafından kolayca kontrol edilebilir.
Temel özellikler:
    PB1 ile saat yönünde, PB2 ile saat yönünün tersinde dönüş.
    PB3 ile hız artırma, PB4 ile hız azaltma (4 seviyeli PWM).
    PB3 ve PB4 aynı anda basıldığında motoru durdurma (simülasyonda ayrı bir stop butonu).
    Kırmızı/yeşil LED ile yön bilgisi, mavi LED ile hız göstergesi.
    LCD ekran ile kullanıcıya hız ve yön bilgisi sağlanması.
Bu sistem, temel motor sürme mantığını kavramak ve mikrodenetleyici uygulamalarıyla donanım kontrolü gerçekleştirmek için ideal bir uygulamadır.

# English
This project demonstrates how to control the speed and direction of a DC motor using Arduino and the L293D H-bridge driver IC. The user can interact with the system using push buttons, while LEDs and an LCD provide real-time visual feedback.
Key features:
    PB1 for clockwise and PB2 for counterclockwise rotation.
    PB3 to increase and PB4 to decrease speed (4-level PWM).
    Pressing PB3 and PB4 together stops the motor (a dedicated stop button used in simulation).
    Red/green LEDs indicate direction, blue LED represents speed level.
    I2C LCD displays motor status and speed.
This is an educational project for understanding motor control principles and implementing hardware interaction through microcontrollers.
