#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// For this homework, you are going to implement an extendable vector based queue that 
// uses "jump" trick to save space. 
// Finish function 
//              front() that prints the first element in the queue
//              deque() that dequeues the queue
//          	enque(val) that enqueues val to the queue
//              print_vect() that prints out vect_que.
// Demonstrate that your code works in main.
// Refer to class PPT if you forgot all the different cases. 

template <class T>
class vect_queue {
private:
	std::vector<T> vect_que;
	size_t size_;
	int que_front_;
public:
	vect_queue(T val) {
		vect_que.push_back(val);
		size_ = 1;
		que_front_ = 0;
	}

    size_t Size()
    {
        return size_;
    }

	T front() const
    {
        if(Size()==0)
        {
            throw std::out_of_range("empty queue");
        }
        return vect_que[que_front_];
    }
    void Resize(){
        size_t newVecSize = size_* 2;
        std::vector<T> newVector(newVecSize,T());
        
        for(size_t i = 0; i<size_; ++i)
        {
            int j = (que_front_ + i) % vect_que.size();
            newVector[i] = vect_que[j];
        }
        vect_que.swap(newVector);
        que_front_= 0;
    }
	void deque(){
        if(Size()==0)
        {
            throw std::out_of_range("empty queue");
        }
        que_front_= (que_front_ + 1) % vect_que.size();
        --size_;
        if(vect_que.size() >= (3*size_)){
            Resize();
        }
    }
	void enque(T val){
        if((size_+1)>vect_que.size())
        {
            Resize();
        }
        size_t i = (que_front_+size_) % vect_que.size();
        vect_que[i] = val;
        ++size_;
    }
	void print_vect() const
    {
        cout << "The front value is: " << que_front_;
        cout << endl << "Vector Elements : ";
        for(int i = 0;i<size_;i++)
        {
            cout << vect_que.at(i)<< ", ";

        }
        cout << endl << "Size = " << size_ << endl;
        cout << endl;
    }
};



int main()
{   
    //Demonstrate your code works by adding/removing values in a vect_que class 
    //object. Print out your result.
    //You should include front index of queue, back index of queue, and the entire
    //vector (not queue) for each case.

    
    //case 1: add to an empty queue
    vect_queue<int> caseOne(1);
    cout << "Case One: \n";
    caseOne.print_vect();

    //case 2: add to a non-empty queue without jump 
    vect_queue<int> caseTwo(1);
    caseTwo.enque(2);
    cout << "Case Two: \n";
    caseTwo.print_vect();

    //case 3: add to a non-empty queue with a jump
    vect_queue<int> caseThree(1);
    caseThree.enque(2);
    caseThree.enque(3);
    caseThree.deque();
    caseThree.enque(4);
    caseThree.enque(5);
    cout << "Case Three: \n";
    caseThree.print_vect();
    //case 4: remove from a queue with number of elements > 1 
    //        and que.front not at vect.back
    vect_queue<int> caseFour(1);
    caseFour.enque(3);
    caseFour.enque(5);
    caseFour.deque();
    cout << "Case Four: \n";
    caseFour.print_vect();

    //case 5: remove from a queue with number of elements > 1 
    //        and que.front at vect.back
    vect_queue<int> caseFive(1);
    caseFive.enque(2);
    caseFive.deque();
    caseFive.enque(3);
    caseFive.enque(4);
    cout << "Case Five: \n";
    caseFive.print_vect();
    //case 6: remove from a queue with 1 element in it and que.front 
    //        not at vect[0]
    vect_queue<int> caseSix(1);
    cout << "Case Six: \n";
    caseSix.print_vect();
    
    

    cout<<"\nprogram ends here.\n";

    return 0;
}