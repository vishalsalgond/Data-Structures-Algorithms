//https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
    q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty()) return -1;
    int pop,count=0;
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
        count++;
    }
    count--;
    while(count--){
        q1.push(q2.front());
        q2.pop();
    }
    pop = q2.front();
    q2.pop();
    return pop;
}
