 # **iCharge**
- See in [English 🇬🇧](./README-en-US.md).

<div>
 <img src="https://user-images.githubusercontent.com/79997705/115066067-62e73e80-9ec5-11eb-963d-0656521801e6.PNG" min-width="400px" max-width="400px" width="400px" alt="" >
<img src="https://user-images.githubusercontent.com/79997705/115066087-6a0e4c80-9ec5-11eb-94dd-dc1e6f635811.PNG" min-width="400px" max-width="400px" width="400px" align="" alt="">
</div>

</br>
O iCharge foi um dos meus projetos de estágio em 2019. Essa é uma aplicação de internet das coisas no qual é possível fazer
o acionamento de um LED através de uma rede local. O microcontrolador usado no projeto é um Arduíno UNO, ele se comunica com
um dispositivo conectado à sua rede através de um módulo Ethernet Shield. 
</br>
Na primeira imagem, podemos ver o LDR que detecta a intensidade de luz e é usado como parâmetro para o acendimento automático do LED branco. Ao lado, temos o LED verde, que é conr controlado da página HTML. No trecho de código abaixo, vemos a configuração dos parâmetros de rede da Ethernet Shield.

```
byte mac[] = {0xDe, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

unsigned short int ldrValor = 0;

//IPAddress ip(10, 33, 250, 117); 
IPAddress ip(192, 168, 0, 105);   // Here, you must put the Arduino's IP 
```

## Linguagens da aplicação
 
![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![image](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)

***
 ![image](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white) 
 
 Visite o meu [LinkedIn](https://www.linkedin.com/in/nathan-de-souza-silva-firmo/). 


