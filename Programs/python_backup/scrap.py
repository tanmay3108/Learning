fo = open("index.txt", "r")
data=fo.read()
begin=0
link=[]
for i in range(24):
    begin=data.find('<a class="quicklooklink"',begin)
    begin=data.find('href',begin)
    end=data.find('pos',begin)    
    link.append(data[begin+6:end-1])
    begin=end
for i in range(24):        
    url="http://www.homeshop18.com"+link[i]    
    response = urllib2.urlopen(url)
    html=BeautifulSoup(response)
    data="hello"

    for elem in html.findAll(['script']):    
        data=data+str(elem.extract())
        variable="var google_custom_params = {"
    begin1=data.find(variable)
    begin1=data.find('{',begin1)
    end=data.find("}",begin1)
    jd=data[begin1:end+1]
    print jd


	
	
	snapdeal
	url="http://www.snapdeal.com/product/nokia-107-dual-sim-red/786894246"
try:
    response = urllib2.urlopen(url)
    a=response.read()
    begin= a.find('<div class="overhid key-features-outer">')
    print begin
    end=a.find('</div>',begin)
    print end    
    print a[begin:end]
    begin= a.find('<div class="priceandofferbox">')
    end=a.find('<span id="discount-id">',begin)
    print a[begin:end+100]
except:
    print "connectivity problem:Check Your internet Connection"