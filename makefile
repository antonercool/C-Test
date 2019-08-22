#Constant
CXX = g++ -std=c++11
CXXFLAGS = -I.
out =  c:/Projects/C-Test/build/


%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
hellomake: student.o main.o data.o 
	$(CXX)  -o program student.o data.o main.o 