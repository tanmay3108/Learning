'''
Created on 06-Mar-2013

@author: Tanmay Sinha
'''
####DATA STRUCTURES###########3
###sequences are the data structures where elements are numbered starting with zero and each element can be accessed wtih those numbers
########## list is mutable sequence while tuple and strings are non mutable
#python has six types of data structures but most common are tuples and lists
##main difference between list and tuples is that list can be changed or altered but tuples can't be changed or altered
#first lets talk about sequences list and tuples are the type of sequences and some of the operations are common for both
a="xyz"
details=["Tanmay",23];
details[0]="sinha"
print details
newdetails=["sinha",43]
details=details+newdetails
print details
numbers=[-1,1,2,3,4,5,6,7,8,9,10]
print numbers[0:]
#here it will print whole sequence from 0 till end 
print numbers[3:7]
#here first parameter is inclusive while second parameter is exclusive
numbers=numbers+details
#numbers=numbers+details+a this is wrong statement because only similar sequences can be added or concatanated though string is also a type of sequence
print numbers
#reverse accesing of the sequence
print numbers[-1]
#here counting starts from right and -1 is the right most element of the sequence 
print numbers[-5:-1]
#here also -5 is inclusive while -1 is exclusive
print numbers[-5:]
#will print the whole sequence from -5 to end of the sequence
print numbers[4:12:2]
#here all the elemnts from 4 inclusive to 12 exclusive will be printed but with skipping of 2
#like adding of the sequence we can even multiply the sequence in case of multiplying we are simply adding the sequence multiplcant number of times
numbers=numbers*2
print numbers
#now we have twice of the number that is contents of the sequence get duplicated
print len(numbers)#here we can find the length of the sequence it will work with string also
print 2 in numbers
print "Tanmay" in numbers
#in is a keyword which is used to find if particular element is in sequence or not and return type is boolean
####now lets start with list.List are mutable that is we can change their contents
x=['h','r','m']
del x[2]
print x
x[1]='m'
x=[1,2,3,4,5]##important we can modify things here very easily
x[3:]=[6,7]##
print x
#name="python" this gives error thus we have to make use of list like done in following lines
#name[1:]="erl";
name=['p','y','t','h','o','n']
name[1:]=['a','p','a']
print name
name=list("python")
name[1:]=list("erl")
print name
print x
#insertion in the list
number=[1,2,3,6,7,8]
number[3:3]=[4,5]
print number
#we can remove any by following
number[1:3]=[]
print number
##methods which can be used are #append#count#extend#index#insert#pop#remove#reverse#sort
### "append" adds the data in the last position of the list
###"count" it counts the number of times particular element has been repeated in the sequence
#####"extend" it act same as the concatenation but it overwrite the sequence which calls it
#########"index" it returns the first index of the element which is being searched
number=[1,2,2,3,"hello","bye"]
x=[3,4,4,5,"hi","take care"]
x.append(number)
print x
print x.count(4)
print x.count(3)#if u notice that three will be coming 2 times after appending x with numbers but it shown only once because number is the sub sequence which is consider as one single element within x thus it will be not counted
number.extend(x)
print number
name="tanmay"
##del name[1]; since its an string and they are a type of tuples hence they wont support deletion
print len(name)
1,2,3##merely writing numbers separated by commas will make it a tuple and string is also a tuple
(1,2,3)###it is same as above
42####not a tuple commas are necessary
42,####this is a tuple
()###empty tuple
print 3*(42+2)#####this is NOT a tuple but a mathematical notation 
print 3*(42+2,)####this is a tuple printing (44,44,44) multiplication if the tuple
tuplenumber=tuple(name)###function tuple returns the tuple of any sequence passed to it and if tuple itself is passes it will return the unchanged tuple
print tuplenumber

