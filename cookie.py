#11
#extracting cookies
import urllib
import http.cookiejar


url="http://www.youtube.com"
def extract_cookies():
    cookie_jar=http.cookiejar.CookieJar()
    url_opener=urllib.request.build_opener(urllib.request.HTTPCookieProcessor(cookie_jar))
    url_opener.open(url)
    for cookie in cookie_jar:
        print("[cookie name=%s] --[Cookie value=%s]" %(cookie.name,cookie.value))
        
        
if __name__=="__main__":
    extract_cookies()
