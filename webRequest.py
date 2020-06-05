#12
import requests
proxies={"https":"191.252.196:160:8080"}
url="https://httpbin.org/ip"
r=requests.get(url)
print(r.json())

