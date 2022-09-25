#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<string.h>
#include <algorithm>
using namespace std;


enum enum_gateType
    {
        And ,
        Or ,
        Nand ,
        Nor ,
        Xor ,
        Xnor,
        Not
    };
class Node
{

private:
    string Name;
    int Value;

public:
    //default ctor
    Node()
    {

    }
    //non default ctor
    Node(string Name,int Value=0):
        Name(Name),
        Value(Value)
    {


    }
    //setter
    void Node_set_name(string Name)
    {
        this->Name=Name;

    }
    void Node_set_value(int Value)
    {
        this->Value=Value;

    }
    //getter
    string Node_get_name()
    {
        return Name;
    }
    int  Node_get_value()
    {
        return Value;
    }
    //gates
    int AND(const Node & object)
    {
        int and_value;
        and_value=Value&&object.Value;
        return and_value;
    }
     int OR(const Node & object)
    {
         int or_value;
        or_value=Value||object.Value;
        return or_value;

    }
     int XOR(const Node & object)
    {
        int xor_value;
        xor_value=Value^object.Value;
        return xor_value;
    }
    //operator overloading
    ostream& operator << (ostream & os)
    {
        os<<Name<<" / "<<Value<<"\n";
        return os;
    }


};

class Gate
{
private:
    enum_gateType GateType;
    string InputN1_name;
    string InputN2_name;
    string OutputN_name;
    Node *InputNode1;
    Node *InputNode2;
    Node *OutputNode;



public:
    //default ctor
    Gate()
    {

    }
    //non default ctor
    Gate(enum_gateType GateType,string Name1,string Name2,string Name3):
        GateType(GateType),
        InputN1_name(Name1),
        InputN2_name(Name2),
        OutputN_name(Name3),
        InputNode1(nullptr),
        InputNode2(nullptr),
        OutputNode(nullptr)
    {


    }
/*
  //all needed to be modified----------------------
    //setters
    void Gate_set_GateType(enum_gateType GateType)
    {
        this->GateType=GateType;
    }
    void Gate_set_Input1Value(int Value)
    {
        InputNode1.Node_set_value(Value);
    }
     void Gate_set_Input2Value(int Value)
    {
        InputNode2.Node_set_value(Value);
    }

    //getters
     int Gate_get_Input1Value()
    {
        return InputNode1.Node_get_value();
    }
     int Gate_get_Input2Value()
    {
        return InputNode2.Node_get_value();
    }
    int Gate_get_OutputValue()
    {
        return OutputNode.Node_get_value();
    }



    int AND()
    {
        OutputNode.Node_set_value(InputNode1.Node_get_value()&&InputNode2.Node_get_value());
        return OutputNode.Node_get_value();
    }
    int OR()
    {
        OutputNode.Node_set_value(InputNode1.Node_get_value()||InputNode2.Node_get_value());
        return OutputNode.Node_get_value();
    }
    int NAND()
    {
        OutputNode.Node_set_value(InputNode1.Node_get_value()&&InputNode2.Node_get_value());
        return !(OutputNode.Node_get_value());
    }
    int NOR()
    {
        OutputNode.Node_set_value(InputNode1.Node_get_value()||InputNode2.Node_get_value());
        return !(OutputNode.Node_get_value());
    }
    int XOR()
    {
        OutputNode.Node_set_value(InputNode1.Node_get_value()^InputNode2.Node_get_value());
        return OutputNode.Node_get_value();

    }
     int XNOR()
    {
        OutputNode.Node_set_value(InputNode1.Node_get_value()^InputNode2.Node_get_value());
        return !(OutputNode.Node_get_value());

    }
     int NOT()
    {
        OutputNode.Node_set_value(!(InputNode1.Node_get_value()));
        return OutputNode.Node_get_value();

    }

    int simulateGate()
    {
        switch(GateType)
        {
        case And:
            return AND();
            break;
        case Or:
            return OR();
            break;
        case Nand:
            return NAND();
            break;
        case Nor:
            return NOR();
            break;
        case Xor:
            return XOR();
            break;
        case Xnor:
            return XNOR();
            break;
        case Not:
            return NOT();
            break;

        default:
            //for no choice of gate
            return -1;
            break;
        }
    }

*/

};


class simulator
{
private:
    vector <Gate*> GateArr;
    vector <Node*> NodeArr;
    //static simulator* Once;

//private constructor to control that it crated once
   simulator()
   {

   }
   simulator (const simulator& object )
   {

   }
   void operator=(const simulator & object)
   {

   }
public:
    static simulator& CreatSimulationOnce()
    {

        static simulator OneInst;
        return OneInst;
    }


    void postGate(Gate * PtrToGate)
    {
        GateArr.push_back(PtrToGate);
    }

    void postNode(Node * PtrToNode)
    {
        NodeArr.push_back(PtrToNode);
    }

    Node * FindNode(string NodeName)
    {
        //1-if empty case

        //2- if not empty
        for (unsigned int i=0 ;i<NodeArr.size(); i++)
        {

            if(NodeArr.at(i)->Node_get_name()==NodeName)
            {

                return & NodeArr.at(i);
            }

        //3-if not found
        }
        return -1;
    }

    //take care
    void startSimulate()
    {
        //for(const Gate* & GatePtrIter:GateArr)
        {

        }
    }

};
class GateGenerator
{
private:
    simulator::CreatSimulationOnce();

public:

    //taking input
    parseInput()
    {

    }
    GateGenerator()
    {

    }
    //creating node
    Node * createNode(string Name)
    {
        Node nod(Name);
        return &nod;
    }

    Gate * createGate(string Name,string ip1,string ip2,string op)
    {
        Gate gate(Name,ip1,ip2,op);
        return &gate;
    }
};




int main()
{

/*
    vector <int> x;
    for (const int& i : x)
    {
        cout<<i<<"\n";
    }
    x.push_back(5);
    x.push_back(6);
     for (const int& i : x)
    {
        cout<<i<<"\n";
    }
    cout<<x.capacity();
*/

    return 0;
}
