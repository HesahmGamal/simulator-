#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<string.h>
#include <sstream>
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
    //for not which take two param
    Gate(enum_gateType GateType,string Name1,string Name3):
        GateType(GateType),
        InputN1_name(Name1),
        OutputN_name(Name3),
        InputNode1(nullptr),
        InputNode2(nullptr),
        OutputNode(nullptr)
    {


    }

  //all needed to be modified----------------------
    //setters
    void Gate_set_GateType(enum_gateType GateType)
    {
        this->GateType=GateType;
    }
    void Gate_set_Input1Value(int Value)
    {
        InputNode1->Node_set_value(Value);
    }
     void Gate_set_Input2Value(int Value)
    {
        InputNode2->Node_set_value(Value);
    }
    void Gate_set_OutputValue(int Value)
    {
        OutputNode->Node_set_value(Value);
    }

     void Gate_set_InputNode1(Node *InputNode1)
    {
        this->InputNode1=InputNode1;
    }
     void Gate_set_InputNode2(Node *InputNode2)
    {
        this->InputNode2=InputNode2;
    }
    void Gate_set_OutputNode(Node *OutputNode)
    {
        this->OutputNode=OutputNode;
    }


    //getters
    enum_gateType Gate_get_GateType()
    {
        return this->GateType;
    }
     int Gate_get_Input1Value()
    {
        return InputNode1->Node_get_value();
    }
     int Gate_get_Input2Value()
    {
        return InputNode2->Node_get_value();
    }
    int Gate_get_OutputValue()
    {
        return OutputNode->Node_get_value();
    }

    string Gate_get_InputName1()
    {
        return InputN1_name;
    }
     string Gate_get_InputName2()
    {
        return InputN2_name;
    }
    string Gate_get_OutputN_name()
    {
        return OutputN_name;
    }



    void AND()
    {
        OutputNode->Node_set_value(InputNode1->Node_get_value()&&InputNode2->Node_get_value());
    }
    void OR()
    {
        OutputNode->Node_set_value(InputNode1->Node_get_value()||InputNode2->Node_get_value());
    }
    void NAND()
    {
        OutputNode->Node_set_value(!(InputNode1->Node_get_value()&&InputNode2->Node_get_value()));
    }
    void NOR()
    {
        OutputNode->Node_set_value(!(InputNode1->Node_get_value()||InputNode2->Node_get_value()));
    }
    void XOR()
    {
        OutputNode->Node_set_value(InputNode1->Node_get_value()^InputNode2->Node_get_value());

    }
     void XNOR()
    {
        OutputNode->Node_set_value(!(InputNode1->Node_get_value()^InputNode2->Node_get_value()));

    }
     void NOT()
    {
        OutputNode->Node_set_value(!(InputNode1->Node_get_value()));
    }

    void simulateGate()
    {
        switch(GateType)
        {
        case And:
            AND();
            break;
        case Or:
            OR();
            break;
        case Nand:
            NAND();
            break;
        case Nor:
            NOR();
            break;
        case Xor:
             XOR();
            break;
        case Xnor:
             XNOR();
            break;
        case Not:
             NOT();
            break;

        default:
            //for no choice of gate
            break;
        }
    }



};


class simulator
{
private:
    vector <Gate*> GateArr;
    vector <Node*> NodeArr;

    Node * NodeTempPtr;
    //static simulator* Once;

//private constructor to control that it crated once
   simulator()
   {

   }
   ~simulator()
   {
    //remove every node in heap
    /*
        for (unsigned int i=0 ;i<NodeArr.size(); i++)
        {
            delete NodeArr.at(i);

        }
        for (unsigned int i=0 ;i<GateArr.size(); i++)
        {
            delete GateArr.at(i);

        }
*/

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
    //to print all values of nodes
    void Print_NodeArrVal()
    {
        for (unsigned int i=0 ;i<NodeArr.size(); i++)
        {
            cout<<NodeArr.at(i)->Node_get_name()<<": "<<NodeArr.at(i)->Node_get_value()<<"\n";

        }
    }
    //to print one vlaue of node
    void Print_NodeOneVal(string NodeName)
    {
         for (unsigned int i=0 ;i<NodeArr.size(); i++)
        {
            if(NodeArr.at(i)->Node_get_name()==NodeName)
            cout<<NodeArr.at(i)->Node_get_name()<<": "<<NodeArr.at(i)->Node_get_value()<<"\n";

        }
    }

    void postGate(Gate * PtrToGate)
    {
        GateArr.push_back(PtrToGate);
    }

    void postNode(Node * PtrToNode)
    { int flag =0;
        //to make sure not repeating the same node
         for (unsigned int i=0 ;i<NodeArr.size(); i++)
        {
            if(NodeArr.at(i)->Node_get_name()==PtrToNode->Node_get_name())
            {
                flag=1;
            }
        }

        if (flag==0)
        {
            NodeArr.push_back(PtrToNode);


        }

    }

    Node * FindNode(string NodeName)
    {
        //1-if empty case

        //2- if not empty
        for (unsigned int i=0 ;i<NodeArr.size(); i++)
        {

            if(NodeArr.at(i)->Node_get_name()==NodeName)
            {

                return  NodeArr.at(i);
            }


        }
        //3-if not found or empty
        NodeTempPtr=new Node(NodeName);
        postNode(NodeTempPtr);

        return NodeArr.at(NodeArr.size()-1);
    }

    //take care
    void startSimulate()
    {
        for (unsigned int i=0 ;i<GateArr.size(); i++)
        {

           GateArr.at(i)->Gate_set_InputNode1(FindNode(GateArr.at(i)->Gate_get_InputName1() ) );
           if(GateArr.at(i)->Gate_get_GateType()!=Not)
           {
               GateArr.at(i)->Gate_set_InputNode2(FindNode(GateArr.at(i)->Gate_get_InputName2() ) );
           }
           GateArr.at(i)->Gate_set_OutputNode(FindNode(GateArr.at(i)->Gate_get_OutputN_name() ) );
           GateArr.at(i)->simulateGate();

        }
    }

};
class GateGenerator
{
private:
    Node * PtrNodeHeap;
    Gate * PtrGateHeap;

public:

    GateGenerator()
    {

    }
    ~GateGenerator()
    {
        delete PtrNodeHeap;
        delete PtrGateHeap;
    }


    Node * createNode(string Name)
    {
        PtrNodeHeap=new Node(Name);
        return PtrNodeHeap;
    }

    Gate * createGate(enum_gateType Name,string ip1,string ip2,string op)
    {
        if(Name==Not)
        {
            PtrGateHeap=new Gate(Name,ip1,op);
            return PtrGateHeap;
        }
        else
        {
            PtrGateHeap=new Gate(Name,ip1,ip2,op);
            return PtrGateHeap;
        }

    }

    //taking input
    void parseInput()
    {
         string t,KeyWord,output,operator1,operator2;
         string NodeName,NodeVal;

      while( getline(cin,t))
     {
            istringstream iss(t);

            while(iss >> KeyWord)
            {

                if (KeyWord=="AND")
                {
                    iss>>operator1;
                    iss>>operator2;
                    iss>>output;
                    //creating gate and put it in the array
                    simulator::CreatSimulationOnce().postGate( createGate(And,operator1,operator2,output) );
                    //creating nodes and put it in the array
                    simulator::CreatSimulationOnce().postNode( createNode(operator1) );
                    simulator::CreatSimulationOnce().postNode( createNode(operator2) );
                    simulator::CreatSimulationOnce().postNode( createNode(output)    );
                }
                else if(KeyWord=="OR")
                {
                    iss>>operator1;
                    iss>>operator2;
                    iss>>output;
                    simulator::CreatSimulationOnce().postGate( createGate(Or,operator1,operator2,output) );
                     //creating nodes and put it in the array
                    simulator::CreatSimulationOnce().postNode( createNode(operator1) );
                    simulator::CreatSimulationOnce().postNode( createNode(operator2) );
                    simulator::CreatSimulationOnce().postNode( createNode(output)    );

                }
                else if(KeyWord=="XOR")
                {
                    iss>>operator1;
                    iss>>operator2;
                    iss>>output;
                    simulator::CreatSimulationOnce().postGate( createGate(Xor,operator1,operator2,output) );
                     //creating nodes and put it in the array
                    simulator::CreatSimulationOnce().postNode( createNode(operator1) );
                    simulator::CreatSimulationOnce().postNode( createNode(operator2) );
                    simulator::CreatSimulationOnce().postNode( createNode(output)    );

                }
                else if(KeyWord=="NAND")
                {
                    iss>>operator1;
                    iss>>operator2;
                    iss>>output;
                    simulator::CreatSimulationOnce().postGate( createGate(Nand,operator1,operator2,output) );
                     //creating nodes and put it in the array
                    simulator::CreatSimulationOnce().postNode( createNode(operator1) );
                    simulator::CreatSimulationOnce().postNode( createNode(operator2) );
                    simulator::CreatSimulationOnce().postNode( createNode(output)    );

                }
                else if(KeyWord=="NOR")
                {
                    iss>>operator1;
                    iss>>operator2;
                    iss>>output;
                    simulator::CreatSimulationOnce().postGate( createGate(Nor,operator1,operator2,output) );
                     //creating nodes and put it in the array
                    simulator::CreatSimulationOnce().postNode( createNode(operator1) );
                    simulator::CreatSimulationOnce().postNode( createNode(operator2) );
                    simulator::CreatSimulationOnce().postNode( createNode(output)    );

                }
                else if(KeyWord=="XNOR")
                {
                    iss>>operator1;
                    iss>>operator2;
                    iss>>output;
                    simulator::CreatSimulationOnce().postGate( createGate(Xnor,operator1,operator2,output) );
                     //creating nodes and put it in the array
                    simulator::CreatSimulationOnce().postNode( createNode(operator1) );
                    simulator::CreatSimulationOnce().postNode( createNode(operator2) );
                    simulator::CreatSimulationOnce().postNode( createNode(output)    );

                }
                 else if(KeyWord=="NOT")
                {
                    iss>>operator1;
                    iss>>output;
                    simulator::CreatSimulationOnce().postGate( createGate(Not,operator1,output,output) );
                    //creating nodes and put it in the array
                    simulator::CreatSimulationOnce().postNode( createNode(operator1) );
                    simulator::CreatSimulationOnce().postNode( createNode(output)    );

                }
                else
                {
                    if(KeyWord=="SET")
                    {
                        iss>>NodeName;
                        iss>>NodeVal;
                        //this function return ptr to int
                        Node* rcv_NodePtr=simulator::CreatSimulationOnce().FindNode(NodeName) ;
                        if(rcv_NodePtr!=nullptr)
                        {
                            rcv_NodePtr->Node_set_value( stoi(NodeVal) );
                        }

                    }

                    else if(KeyWord=="SIM")
                    {
                        simulator::CreatSimulationOnce().startSimulate();
                    }

                     else if(KeyWord=="OUT")
                    {
                        iss>>NodeName;
                        if (NodeName=="ALL")
                        {
                            simulator::CreatSimulationOnce().Print_NodeArrVal();
                        }
                        else
                        {
                            simulator::CreatSimulationOnce().Print_NodeOneVal(NodeName);
                        }

                    }

                    else
                    {
                      //here if you want to debug something
                    }



                }

            }

     }


    }


};




int main()
{
GateGenerator GATE_GEN;
GATE_GEN.parseInput();

    return 0;
}
