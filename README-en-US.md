 # **ICharge**

- Ver em [Português 🇧🇷](./README.md).

<div>
 <img src="https://user-images.githubusercontent.com/79997705/115066067-62e73e80-9ec5-11eb-963d-0656521801e6.PNG" min-width="400px" max-width="400px" width="400px" alt="" >
<img src="https://user-images.githubusercontent.com/79997705/115066087-6a0e4c80-9ec5-11eb-94dd-dc1e6f635811.PNG" min-width="400px" max-width="400px" width="400px" align="" alt="">
</div>

</br></br>
ICharge was one of my internship projects in 2019. This is an internet of things application that you can do
the activation of an LED through a local network. The microcontroller used in the project is an UNO Arduino, it communicates with
a device connected to your network via an Ethernet Shield module.
</br></br>
In the first image, we can see the LDR that detects the light intensity and is used as a parameter for the automatic lighting of the white LED. Beside, we have the green LED, which is controlled from the HTML page. In the code snippet below, we see the configuration of the Ethernet Shield's network parameters.
</br></br>

```
byte mac[] = {0xDe, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

unsigned short int ldrValor = 0;

//IPAddress ip(10, 33, 250, 117); 
IPAddress ip(192, 168, 0, 105);   // Here, you must put the Arduino's IP 
```
## Application languages
 
![image](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![image](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)

***
 ![image](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white) 
 
 Visit my [LinkedIn](https://www.linkedin.com/in/nathan-de-souza-silva-firmo/). 


