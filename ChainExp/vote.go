package main

import(
	"fmt"
	"encoding/json"
	"bytes"
	"github.com/hyperledger/fabric/core/chaincode/shim"
	"github.com/hyperledger/fabric/protos/peer"
)

type VoteChaincode struct {
}

type Vote struct {
	Candidate string
	Votenum int
}

func (t *VoteChaincode) Init(stub shim.ChaincodeStubInterface) peer.Response {
	return shim.Success(nil)
}

func (t *VoteChaincode) Invoke(stub shim.ChaincodeStubInterface) peer.Response {

	fn , args := stub.GetFunctionAndParameters()

	if fn == "setVote" {
		return t.setVote(stub,args)
	} else if fn == "getVote" {
		return t.getVote(stub,args)
	}

	return shim.Error("Invoke failed！")
}

func (t *VoteChaincode) setVote(stub shim.ChaincodeStubInterface , args []string) peer.Response{
	vote := Vote{}
	candidate := args[0]
	voteAsBytes, err := stub.GetState(candidate)

	if err != nil {
		shim.Error("setVote getstate failed！")
	}

	if voteAsBytes != nil {
		err = json.Unmarshal(voteAsBytes, &vote)
		if err != nil {
			shim.Error(err.Error())
		}
		vote.Votenum += 1
	}else {
		vote = Vote{ Candidate: args[0], Votenum: 1} 
	}

	voteJsonAsBytes, err := json.Marshal(vote)
	if err != nil {
		shim.Error(err.Error())
	}

	err = stub.PutState(candidate,voteJsonAsBytes)
	if err != nil {
		shim.Error("setVote putstate failed！")
	}

	return shim.Success(nil)
}

func (t *VoteChaincode) getVote(stub shim.ChaincodeStubInterface, args []string) peer.Response{

	resultIterator, err := stub.GetStateByRange(args[0], args[1])
	if err != nil {
		return shim.Error(" getstatebyrange failed ")
	}
	defer resultIterator.Close()

	var buffer bytes.Buffer
	for resultIterator.HasNext() {
		queryResult , err := resultIterator.Next()
		if err != nil {
			return shim.Error(err.Error())
		}
		buffer.WriteString("\n")
		buffer.WriteString(string(queryResult.Value))
	}

	fmt.Printf("Result：%s\n",buffer.String())
	return shim.Success(buffer.Bytes())
}

func main(){
	err := shim.Start(new(VoteChaincode))
	if err != nil {
		fmt.Println("vote chaincode start err")
	}
}
