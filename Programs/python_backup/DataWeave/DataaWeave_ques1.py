from bs4 import BeautifulSoup
import urllib2
import csv
json_data=""
Specs=""
keyword=[]
link=[]
li=[]
flink=[]#Final links from where data has to scraped in SnapDeal
fo = open("index.txt", "r")
data=fo.read()
begin=0
parsed=[]
parsedSD=[]
total_product=0
csv_string=""
csv_i=1
csv_data=[]
notfound=[]#Links not found in Snapdeal
csv_data.append("Homeshop18_product_title,Homeshp18_MRP,Snapdeal_MRP,Homeshop18_selling_price,Snapdeal_selling_price,Homeshop18_stock_status,Snapdeal_stock_status".split(","))
def parse(jd,begin,end,data):             
        begin=jd.find("pname")
        begin=jd.find("[",begin)
        end=jd.find("]",begin)
        parsed.append(jd[begin+2:end-1])
        begin=jd.find("pcat")
        begin=jd.find("[",begin)
        end=jd.find("]",begin)        
        parsed.append(jd[begin+2:end-1])
        begin=jd.find("psubcat")
        begin=jd.find("[",begin)
        end=jd.find("]",begin)
        parsed.append(jd[begin+2:end-1])
        begin=jd.find("pvalues")
        begin=jd.find("[",begin)
        end=jd.find("]",begin)
        parsed.append(jd[begin+2:end-1])
        begin=jd.find("prodId")
        begin=jd.find("[",begin)
        end=jd.find("]",begin)
        parsed.append(jd[begin+2:end-1])
        begin=end=0
        variable='var data'
        begin=data.find(variable)
        begin=data.find('"items"',begin)
        begin=data.find('"mrp"',begin)
        begin=data.find(':',begin)
        end=data.find(',',begin)
        parsed.append(data[begin+1:end])
        begin=data.find(variable)
        begin=data.find('"items"',begin)
        begin=data.find('"stockQuantity"',begin)
        begin=data.find(':',begin)
        end=data.find(',',begin)
        parsed.append(data[begin+1:end])
        
                                                 


#Extracting links from the url given in the Question
for i in range(24):#(24):
    begin=data.find('<a class="quicklooklink"',begin)
    begin=data.find('href',begin)
    end=data.find('pos',begin)    
    link.append(data[begin+6:end-1])
    begin=end
print "All the link from the Given URL Fetched"
print "Fetching Json format from the Above Fetched Links...."
    
for i in range(len(link)):        
    url="http://www.homeshop18.com"+link[i]
    try:                    
        response = urllib2.urlopen(url)
        print "Fethching..."+str(i+1)
    except:
        print "Connection Failure"    
    html=BeautifulSoup(response)
    data=""
    for elem in html.findAll(['script']):    
        data=data+str(elem.extract())
        variable="var google_custom_params = {"
    begin1=data.find(variable)
    begin1=data.find('{',begin1)
    end=data.find("}",begin1)    
    #print data[begin2:end2-1]#MRp and Stock Quantity
    json_data=json_data+ data[begin1:end+1]+'\n\n\n'#details from the Home shop 18 json data
    jd=data[begin1:end+1]
    parse(jd,begin,end,data)
    begin=jd.find("pname")
    begin=jd.find("[",begin)
    end=jd.find("]",begin)
    keyword.append(jd[begin+2:end-1])

print "Fethced "+str(len(parsed))+"Json Data from HomeShop18"        
print "Above phones have to be searched in Snapdeal"
#here we picked up all the mobile phones present on site homeshop and prepeared keyword for searching in snapdeal    

for i in range(len(link)):
    url='http://www.snapdeal.com/search?keyword='
    keyword[i]=keyword[i].replace(' ','+')
    end2=keyword[i].find('+')
    end2=keyword[i].find('+',end2+1)
    end2=keyword[i].find('+',end2+1)     
    url=url+(keyword[i])[0:end2]    
    url1='&santizedKeyword='+(keyword[i])[0:end2]
    url=url+url1    
    url2='&catId=&categoryId=175&suggested=true&vertical=p&noOfResults=20&clickSrc=suggested&lastKeyword=&prodCatId=&changeBackToAll=false&foundInAll=false&categoryIdSearched=&cityPageUrl=&url=&utmContent=&catalogID=&dealDetail='
    url= url+url2 #list of urls to be searched in snapdeal
    #print url        
    print "Searching and Scraping Snapdeal for..."+str(i)+"of 20 Links"
    begin=0
    response = urllib2.urlopen(url)
    a=response.read()    
    for j in range(10): #no of results displayed in one search   
        begin= a.find('<div class="product_grid_box">',begin)
        if begin==-1:
            break
        begin=a.find('<a href=',begin)
        end=a.find('v="p"',begin)
        #print a[begin+9:end-2]
        begink=a.find('product',begin)
        endk=a.find('/',begink+9)
        k=a[begink+8:endk]#keywords present in the url return
        k=k.split('-')        
        k2=(keyword[i].lower()).split('+')#Required keywords string changed to list 0 because first 
        
        try:
            result=(k[0]in(k2))+(k[1]in(k2))+(k[2]in(k2))
            #print result
        except:
            continue    
        if result<3:
            begin=end
            continue    
            
        li.append(a[begin+9:end-2])            
        begin=end
    try:
        flink.append(li[0])
        li=[]
    except:
        print "Product Not Found at first search"+keyword[i]
        li=[]
        notfound.append(i)
        pass  
print "Strarting Second Search"  #For the keyword for which links not found
if len(notfound)!=0:
    for jj in range(len(notfound)):
        url='http://www.snapdeal.com/search?keyword='
        print keyword[notfound[jj]]
        end2=keyword[notfound[jj]].find('+')
        end2=keyword[notfound[jj]].find('+',end2+1)
        url=url+(keyword[notfound[jj]])[0:end2]            
        url1='&santizedKeyword='+(keyword[notfound[jj]])[0:end2]
        url=url+url1    
        url2='&catId=&categoryId=175&suggested=true&vertical=p&noOfResults=20&clickSrc=suggested&lastKeyword=&prodCatId=&changeBackToAll=false&foundInAll=false&categoryIdSearched=&cityPageUrl=&url=&utmContent=&catalogID=&dealDetail='
        url= url+url2 #list of urls to be searched in snapdead
        print url
        print "Searching in Snapdeal for..."+str(notfound[jj])+"of 24 Links"
        begin=0
        response = urllib2.urlopen(url)
        a=response.read()    
        for jjj in range(10): #no of results displayed in one search   
            begin= a.find('<div class="product_grid_box">',begin)
            if begin==-1:
                break
            begin=a.find('<a href=',begin)
            end=a.find('v="p"',begin)
            #print a[begin+9:end-2]
            begink=a.find('product',begin)
            endk=a.find('/',begink+9)
            k=a[begink+8:endk]#keywords present in the url return
            k=k.split('-')
            #print k
            k2=(keyword[notfound[jj]].lower()).split('+')#Required keywords string changed to list 0 because first w
            #print k2
            try:
                result=(k[0]in(k2))+(k[1]in(k2))
                print result
            except:
                continue    
            if result<2:                
                begin=end
                continue    
            
            li.append(a[begin+9:end-2])            
            begin=end
        try:
            print li
            flink.insert(notfound[jj],li[0])
            li=[]
        except:
            print "Product Not Found at Second  search"+keyword[notfound[jj]]
            li=[]
            notfound.append(i)
            pass
    
          
      
#for m in range(len(link)):
#    try:        
#        print flink[m]
#    except:
#        pass    
print "Length of "+str(len(flink))#number of links to be searched    

#printing details from the Snapdeal      
print("Parsing Data From Snapdeal...")      
for i in range(len(flink)):
        try:            
            response = urllib2.urlopen(flink[i])
            print("Parsing From Link "+str(i+1))
        except:
            print("Connection Failure on Parsing SnapDeal")
        a=response.read()
        begin=a.find('<h1 itemprop="name">')
        end=a.find('</h1>')
        soup=BeautifulSoup(a[begin:end])
        s=soup.get_text()
        s=s.replace('\n',' ')
        Specs=Specs+s+'\n'                             
        begin= a.find('<div class="priceandofferbox">')
        end=a.find('<span id="discount-id">',begin)     
        soup = BeautifulSoup(a[begin:end+100])    
        s=soup.get_text()
        s=s.replace('\n',' ')
        s=s.strip(' ')
        temp=s.split(' '); #temp[2] mrp temp[16] offered price temp[18] discount
        parsedSD.append(temp[2]) 
        parsedSD.append(temp[16])
        parsedSD.append(temp[18])
        begin= a.find('<div class="overhid key-features-outer">')        
        end=a.find('</div>',begin)  
        soup = BeautifulSoup(a[begin:end+100])
        s=soup.get_text()
        s=s.replace('\n',"  ")
        s=s.strip(' ')
        Specs=Specs+s+'\n'        
        #print s     

print "Creating CSV Report..."        
total_product=((len(parsed)+1)/7)
for ii in range(total_product):            
    csv_string=parsed[ii*7]+"," #title
    csv_string=csv_string+parsed[ii*7+5]+"," #mrp homeshop_18
    csv_string=csv_string+parsedSD[ii*3]+","   #mrp snapdeal
    csv_string=csv_string+parsed[ii*7+3]+","   #offered price Home Shop  
    csv_string=csv_string+parsedSD[ii*3+1]+","   #offered price snapdeal
    csv_string=csv_string+parsed[ii*7+6] #   #stock_home_shop
    csv_string=csv_string+'Available'
    csv_data.append(csv_string.split(","))

path="output.csv"
with open(path, "wb") as csv_file:
    writer = csv.writer(csv_file, delimiter=',')
    for line in csv_data:
        writer.writerow(line)

        
print("Writng Json Data to file...")
file1=open("json_homeshop_18.txt", "wb")
file1.write(json_data)
file1.close()
print("Writng Specification Data to file...")
file1=open("Specification.txt", "wb")
file1.write(Specs)
print ("Done")
