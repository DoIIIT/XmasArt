import requests  

r = requests.post("https://api.particle.io/v1/devices/310030000847343337373738/ledstrip", 
                    	data = {"access_token":"de293c5824b7d56ce71701a26e55916c7fbbbf0f",
                    	"params":"off"
                    	})