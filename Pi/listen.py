# dash-listen.py
from scapy.all import *  
import requests  
import time
from datetime import datetime

ZIPLOC_MAC_ADDR = '...'

def play_pause_sonos():  
    print("Triggering Play Sonos script")
  # os.system("osascript play-sonos.scpt") 


def arp_display(pkt):
    if pkt.haslayer(ARP):
        if pkt[ARP].op == 1: #who-has (request)
            if pkt[ARP].psrc == '0.0.0.0': # ARP Probe
                if pkt[ARP].hwsrc == '74:c2:46:aa:74:eb': # Huggies
                    print "[%s] Detected"%datetime.now()
                    r = requests.post("https://api.particle.io/v1/devices/310030000847343337373738/ledstrip", 
                    	data = {"access_token":"de293c5824b7d56ce71701a26e55916c7fbbbf0f",
                    	"params":"off"
                    	})
                else:
                    print "ARP Probe from unknown device: " + pkt[ARP].hwsrc

print sniff(prn=arp_display, filter="arp", store=0)  