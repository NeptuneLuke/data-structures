/**
* @author 	Luca Cortinovis	luca1cortinovis@gmail.com
* @version 	1.0
* @since	25/5/2021
*
* You can find me here:
* GitHub	Luca Cortinovis(NeptuneLuke)
*/


public class LinkedList {
    
	
	private class Node {
		
		private int data;
		private Node next;
    	}
    
	private Node head;
	
	/* --------------------------------- */
	//create an empty list
    	public LinkedList() {
		
		head = null;
   	}
    
    //create a list with a node
    public LinkedList(int k) {
		
		head = new Node();
		head.data = k;
		head.next = null;
    }
    
	//destroy the list
    public void destroy(){
		
		head = null;
    }
    /* --------------------------------- */
	
	
	
	/* --------------------------------- */
	//return true if the list is empty, false otherwise
	public boolean listEmpty() {
	
		if(head == null)
			return true;
		else
			return false;
    }
	
	//return true if the element is in the list
	public boolean exist(int k) {
	
		if(head == null)
    		return false;
    	else {
    		
			Node app = head;
			boolean found = false;
			
			while(!found && app != null) {
				
				if(app.data == k)
					found = true;
				
				app = app.next;
			}
			
			return found;
    	}
		
    }
	
	//extract the first node containing k
    public Node extractFirstNode(int k) {
    	
		if (head == null || !this.exist(k)) {
			return null;
		}
		else {
			
			Node app = head;
			
			while(app != null) {
				
				if(app.data == k) 
					break;
				else
					app = app.next;
			}
			
			return app;
		}
		
    }
    
	//extract the last node containing k
    public Node extractLastNode(int k) {
    	
		this.reverse();
		Node extract = this.extractFirstNode(k);
		this.reverse();
		return extract;
    	
    }
	
	//return number of nodes with value k
	public int countValues(int k) {
		
		if(head == null || !this.exist(k))
			return 0;
		else {
			
			Node app = head;
			int count = 0;	
			
			while(app != null) {
					
				if(app.data == k)
					count++;
				
				app = app.next;
			}
			
			return count;
		}
		
    }
	
	//extract all nodes containing k
	public LinkedList extractAll(int k) {
    	
		if (head == null || !this.exist(k))
			return null;
		else {
			
			LinkedList temp = new LinkedList();
			Node app = head;
	    	
			while(app != null) {
				
				if(app.data == k)
					temp.insertAsFirst(app.data);
				
				app = app.next;
			}
			
	    	return temp;
		}
		
	}
	/* --------------------------------- */
	
	
	
	/* --------------------------------- */
	//add a node to the head of the list
    public void insertAsFirst(int k) {
		
		Node n = new Node();
		n.data = k;
		n.next = head;
		head = n;
    }
	
	//delete the first node (move the head to the right)
	public boolean deleteFirst() {
		
		if (head == null) 
			return false;
		else {
			head = head.next;
			return true;
		}
		
    }
	
	//insert node at the end of the list
	public void insertAsLast(int k) {
	
		if(head == null)
			insertAsFirst(k);
		else {
			
			Node app = head;
			
			while(app.next != null)
				app = app.next;
			
			Node newNode = new Node();
			newNode.data = k;
			app.next = newNode;
		}
		
	}
	
	//delete the last node of the list
	public boolean deleteLast() {
		
		if(head == null)
			return false;
		else {
			if(head.next == null) {
				this.destroy();
			}
			else {
				
				Node app = head;
				
				while(app.next.next != null)
					app = app.next;
				
				app.next = null;
			}
			
			return true;
		}
		
	}
	
	//insert the data at the given position, so the index of the previous node 
	//in that position become pos+1
    public boolean insertAt(int data, int pos) {
      
    	if(head == null || pos <= 0 || pos > this.size())
    		return false;
    	else {
    		
    		if(pos == 1) {
				this.insertAsFirst(data);
        	}
			else {
				
				Node node = new Node();
            	node.data = data;
            	node.next = head;
            	Node app = head;
            	int index = 1;
            	
            	while(index < pos-1) {
            	    app = app.next;
            	    index++;
            	}
            	node.next = app.next;
            	app.next = node;
			}
			
			return true;
    	}
    	
    }
	
	//delete the node at position pos
	public boolean deleteAt(int pos) {

		if(head == null || pos <= 0 || pos > this.size())
			return false;
		else {
			
			if(pos == 1) {
	    		head = head.next;
	    	}
	    	else {
	    		
	    		Node app = head;
	    		Node prev = head;
	    		int index = 1;
	    		
		    	while(index < pos) {
		    		prev = app;
		    		app = app.next;
		    		index++;
		    	}
		    	prev.next = app.next;
	    	}
			
			return true;
		}
		
    }
	
	//delete all the nodes containing the value k
    public boolean deleteAllData(int k) {

		if(head == null || !this.exist(k))
			return false;
		else {
			
			Node app = head;
			
			while(head.data == k)
				head = head.next;
			
			while(app.next != null) {
				
				if (app.next.data == k)
					app.next = app.next.next;
		        else
		            app = app.next;
			}
			
			return true;
		}
		
	}
	/* --------------------------------- */
	
	
	
	/* --------------------------------- */
	//return the first node of the list
	public Node getFirstNode() {
		
    	if(head == null)
    		return null;
    	else
    		return head;
    }
    
	//return the first data of the list
    public int getFirstData() {
		
    	Node app = getFirstNode();
    	if(app == null) {
    		System.out.println("Impossible to return the first data");
    		return -1;
    	}
    	else
    		return app.data;
    	
    }
	
	//return the last node of the list
	public Node getLastNode() {
		
    	if(head == null)
    		return null;
    	else {
    	
    		this.reverse();
    		Node lastNode = this.getFirstNode();
    		this.reverse();
			
    		return lastNode;
    	}
		
    }
    
	//return the last data of the list
    public int getLastData() {
		
    	Node app = getLastNode();
    	if(app == null) {
			System.out.println("Impossible to return the last data");
			return -1;
		}
    	else
    		return app.data;
    }
	
	//return the node at the given position pos
	public Node getNodeAt(int pos) {

    	if(head == null || pos <= 0 || pos > this.size())
    		return null;
    	else {
			
    		if(pos == 1)
    			return this.getFirstNode();
			else {
				
				Node app = head;
		    	int index = 1;
		    	
				while(index < pos) {
		    		app = app.next;
		    		index++;
		    	}
				
		    	return app;
			}
    	}
		
    }
    
	//return the data at the given position pos
    public int getDataAt(int pos) {

    	Node app = getNodeAt(pos);
    	if(app == null) {
			System.out.println("Impossible to return the data at the specified position");
			return -1;
		}
    	else
    		return app.data;
    }
	
	//set the data of the first node of the list to newData
	public boolean setFirstData(int newData) {
    	
    	if(head == null)
    		return false;
    	else {
    		head.data = newData;
    		return true;
    	}
    	
    }
	
	//set the data of the last node of the list to newData
	public boolean setLastData(int newData) {
    	
    	if(head == null)
    		return false;
    	else {
    		
    		this.getLastNode().data = newData;
    		
    		return true;
    	}
		
    }
	
	//set the data of the node at given position to newData
	public boolean setDataAt(int newData, int pos){

    	if(head == null || pos > this.size() || pos < 0) {
    		return false;
    	}
    	else {
			
    		this.getNodeAt(pos).data = newData;
			
    		return true;
    	}
		
    }
	
	//swap the node at given positions
    public void swap(int pos1, int pos2) {
    	
    	if(head != null && (pos1 <= this.size() && pos1 > 0 && pos2 <= this.size() && pos2 > 0)) {
    		
    		if(pos1 != pos2) {
    			
        		//order the indexes, so that pos1 < pos2 always
        		if(pos2 < pos1) {
        			int posTemp = pos2;
        			pos2 = pos1;
        			pos1 = posTemp;
        		}
    			
        		Node app1 = this.getNodeAt(pos1);
    			Node app2 = this.getNodeAt(pos2);
    			Node prev1 = this.previous(app1);
    			Node prev2 = this.previous(app2);
    			
    			if(prev1 != null)
    			    prev1.next = app2;
    			else
    			    head = app2;
    			    
    			if(prev2 != null)
    			    prev2.next = app1;
    			else
    			    head = app1;
    			      
    			 Node tmp = app1.next;
    			 app1.next = app2.next;
    			 app2.next = tmp;
    		}
    	}
    	
    }
	
    //swap the given nodes
    public void swap(Node first, Node second) {
    	
    	if(head != null && first != null && second != null)
    		swap(this.indexOf(first),this.indexOf(second));
    	
    }
    
	//return the index of the given node
	public int indexOf(Node node) {
    	
    	if(head == null || node == null) {
			System.out.println("Impossible to return the index of the specified node");
			return -1;
		}
    	else {
    		
    		Node app = head;
    		int index = 1;
    		
			while(index < this.size()) {
    			
    			if(app.equals(node))
    				break;
    				
    			app = app.next;
    			index++;
    		}
			
    		return index;
    	}
    	
    }
	
	//return the previous node of the given node
	public Node previous(Node node) {
    	
    	if(head == null || node == null || node.equals(head))
    		return null;
    	else {
    		
    		Node app = head;
    		
    		while(!node.equals(app.next))
        		app = app.next;
    	
    		return app;
    	}
		
    }
    
	//return the previous node of the node at given position
    public Node previous(int pos) {
    	
    	Node app = previous(this.getNodeAt(pos));
        if(app == null)
        	return null;
        else
        	return app;
    }
	
	//return the successor node of the given node
	public Node successor(Node node) {
    	
    	if(head == null || node == null || node.next == null)
    		return null;
    	else
    		return node.next;
		
    }
    
	//return the successor node of the node at given position
    public Node successor(int pos) {
    	
    	if(head == null)
    		return null;
    	else
    		return this.getNodeAt(pos).next;
    }
	
	//replace the node at the given position with the node newNode
	public boolean replaceNodeAt(Node newNode, int pos) {
    	
    	if(head == null || newNode == null || pos <= 0 || pos > this.size())
    		return false;
    	else {
    		
    		Node temp = new Node();
    		temp.data = newNode.data;
    		
			if(pos == 1) {    		
        		
    			temp.next = head.next;
        		head = temp;
        	}
    		else {
    			
				Node app = head;
    			int index = 1;
    			
    			while(index < pos-1) {
    				app = app.next;
    	    		index++;
    	    	}
    			
    			temp.next = app.next.next;
    			app.next = temp;
    		}
			
			return true;
    	}
		
    }
	
	//replace the given node with the node newNode
	public boolean replaceNodeAt(Node newNode, Node node) {
	    	
	    if(head == null || newNode == null)
	    	return false;
	    else
	    	return replaceNodeAt(newNode,this.indexOf(node));
	}
	/* --------------------------------- */
	
	
	
	/* --------------------------------- */
	//duplicates the list, if the list is modified by the instance (this)
	//also the list which invoke the method is modified
	//because they share the same head
    public LinkedList duplicate() {
    	
    	return this;
    }
	
	//copy all the nodes of the instance list into new nodes of a new list
    public LinkedList copy() {
		
    	if(head == null)
    		return null;
    	else {
    		
    		LinkedList copyList = new LinkedList();
    		copyList.head = copy(head);
    		return copyList;
    	}
		
	}
     
    private Node copy(Node app) {
		
    	Node n = new Node();
    	n.data = app.data;
    	
		if(app.next != null)
    		n.next = copy(app.next);
		
    	return n;
    }
	
	//concatenate this+theList
	public LinkedList concatenate(LinkedList secondList) {
		
    	if(head == null || secondList == null)
    		return null;
    	else {
    		
    		LinkedList copy1 = this.copy();
    		LinkedList copy2 = secondList.copy();
    		
    		if (copy2.head == null) 
    			return copy1;
    		
    		else if (copy1.head == null) 
    			return copy2;
    		
    		else {
    			
				Node app = copy1.head;
				
				while(app.next != null) 
					app = app.next;
				
				app.next = copy2.head;
				
				return copy1;
			}
    	}
		
	}
	
	//order the list by swapping the nodes
	//bubbleSort
	public void orderNodes() {
		
		boolean swapFlag = true;
		
		while(swapFlag) {
			
			swapFlag = false;
			for(int i=1; i<this.size(); i++) {
				
				if(this.getDataAt(i) > this.getDataAt(i+1)) {
					
					swap(this.getNodeAt(i),this.getNodeAt(i+1));
					swapFlag = true;
				}
			}
		}
		
	}
	
	//order the list by swapping the data
	//bubbleSort
	public void orderData() {
		
		boolean swapFlag=true;
		
		while(swapFlag) {
			
			swapFlag = false;
			for(int i=1; i<this.size(); i++) {
				
				if(this.getDataAt(i) > this.getDataAt(i+1)) {
					
					int tmp = this.getDataAt(i);
					setDataAt(this.getDataAt(i+1),i);
					setDataAt(tmp,i+1);
					
					swapFlag = true;
				}
			}
		}
		
	}
	
	//reverse the list
	public void reverse() {
		
		//there is more than one element
		if (head != null && head.next != null)
			head = reverse(head);
		
	}
	
	private Node reverse(Node app) {
		
		//there is one element
		if (app.next == null) 
			return app;
		
		
		Node rev = reverse(app.next);   //recursively reverse the list starting from the successor of app
		app.next.next = app;			//now the successor of app points to app
		
		app.next = null; 				//the given list is fully reversed
		return rev;
    }
	
	//cut the list from fromNode (included) to the end of the list
	public void cutEnd(Node fromNode) {
    	
    	if(head != null &&  fromNode != null)
    		cutEnd(this.indexOf(fromNode));
		
    }
	
	//cut the list from pos(included) to the end of the list
    public void cutEnd(int pos) {
    	  	
    	if(head != null) {
    		if(pos > 0 && pos <= this.size()) {
    			
    			int index = pos;
    			
            	while(index <= this.size()) {
            		deleteAt(index);
            		//index doesn't incremate because deleteAt does all the job
            		//till the end of the list
            	}
    		}
    	}
		
    }
	
	//cut the list from fromPos(included) to toPos(excluded)
	public void cutFromTo(int fromPos, int toPos) {
    	
    	if(head != null && fromPos != toPos) {
    		
    		if(toPos == this.size()+1)
    			cutEnd(fromPos);
    		
    		else if(fromPos+1 == toPos)
    			deleteAt(fromPos);
    			
    		else if(fromPos > 0 && fromPos <= this.size() && toPos <= this.size()) {
    			
    			int index = fromPos;
            	
    			while(index < toPos) {
            		deleteAt(index);
            		//index doesn't incremate because deleteAt does all the job
            		//till the end of the list
            		toPos--;
            	}
    		}
    	}
		
    }
    
    //cut the list from fromNode(included) to toNode(excluded)
    public void cutFromTo(Node fromNode, Node toNode) {
    	
    	if(head != null && fromNode != null && toNode != null)
    		cutFromTo(this.indexOf(fromNode),this.indexOf(toNode));
    	
    }
	
    //cut the edges of the list, deleting the first and the last node
    public void cutEdges() {
    	
    	if(head != null) {
    		this.deleteFirst();
        	this.deleteLast();
    	}
    	
    }
    
	//return a inner list from fromPos(included) to toPos(excluded)
    public LinkedList subList(int fromPos, int toPos) {
    	
    	if(head == null || fromPos > this.size() || fromPos < 0 || toPos > this.size()+1 || fromPos == toPos)
    		return null;
    	else {
    		
    		LinkedList sub = new LinkedList();
    		
    		if(fromPos == toPos)
    			sub.insertAsFirst(this.getNodeAt(fromPos).data);
    		
    		else{
    			
    			Node app = new Node();	
    			
    			while(fromPos < toPos) {
    	        		
    				app.data = this.getDataAt(fromPos);
    	        			
    	        	if(sub.head == null)
    	        		sub.insertAsFirst(app.data);
    	        	else
    	        		sub.insertAsLast(app.data);
    	        			
    	        	fromPos++;
    			}			
    		}
    		
    		return sub;
    	}
    	
    }
    
  //return a inner list from fromPos(included) to toPos(excluded)
    public LinkedList subList(Node fromNode, Node toNode) {
    	
    	if(head != null && fromNode != null && toNode != null)
    		return subList(this.indexOf(fromNode),this.indexOf(toNode));
    	else
    		return null;
    }
    
    //return a list which is the merge of two lists (concat + order)
    public LinkedList merge(LinkedList secondList) {
    	
    	if(head == null || secondList == null)
    		return null;
    	else {
    		
    		//don't make a copy of the lists because it already does 
    		//the method concatenate (both for this and secondList)
    		LinkedList mergeList = this.concatenate(secondList);
    		mergeList.orderData();
    		
    		return mergeList;
    	}
    	
    }
	/* --------------------------------- */
	
	
	
	/* --------------------------------- */
	//return the size of the list
	public int size() {
		
		return size(head);
    }

    private int size(Node app) {
		
		if(app == null)
			return 0;
		else
			return 1 + size(app.next);
    }
	
	//print the list(displaying data)
	public void print() {

    	if(head == null)
    		System.out.println("The list is empty");
    	else {
    		System.out.println("Data in the list: ");
			
			Node app = head;
			
			while(app != null) {
				
				if(app.next == null)
					System.out.print(app.data);
				else
					System.out.print(app.data + " -> ");
				
				app = app.next;
			}
		}
		
    }
	
	//print the list(displaying references of the nodes)
	public void printReference() {
		
    	if(head == null)
    		System.out.println("The list is empty");
		else {
			System.out.println("Reference in the list: ");
			
			Node app = head;
			int i = 1;
			
			while(i <= this.size()) {
				
				if(app.next == null) {
					System.out.print(this.getLastNode());
					i = this.size()+1;
				}
				else {
					System.out.print(this.getNodeAt(i) + " -> ");
					app = app.next;
					i++;
				}
			}
		}
		
    }
	
	//print the list in reverse order(displaying data)
	public void printReverse() {

		if(head == null)
			System.out.println("The list is empty");
		else {
			System.out.println("Data of the list (printed from last to first): ");
			
			this.reverse();
			this.print();
			this.reverse();
		}
		
	}
	
	//print the list in reverse order(displaying data)
	public void printReverseReference() {

		if(head == null)
			System.out.println("The list is empty");
		else {
			System.out.println("Data of the list (printed from last to first): ");
				
			this.reverse();
			this.printReference();
			this.reverse();
		}
			
	}
	/* --------------------------------- */
	
	
	
	/* --------------------------------- */
	//multiply all the data of the nodes of the list by k
	public void multiplyBy(int k) {
		
    	if(head != null) {
			
    		Node app = head;
        	while(app != null) {
        		app.data *= k;
        		app = app.next;
        	}
    	}
		
    }
	
	//divide all the data of the nodes of the list by k
	public void divideBy(int k) {
    	
    	if(head != null) {
			
	    	Node app = head;
	    	while(app != null) {
	    		app.data /= k;
	    		app = app.next;
	    	}
    	}
		
    }
	
	//sum all the data of the nodes of the list by k
	public void sumBy(int k) {
		
    	if(head != null) {
			
	    	Node app = head;
	    	while(app != null) {
	    		app.data += k;
	    		app = app.next;
	    	}
    	}
		
    }
    
	//subtract all the data of the nodes of the list by k
    public void subtractBy(int k) {
		
    	if(head != null) {
			
	    	Node app = head;
	    	while(app != null) {
	    		app.data -= k;
	    		app = app.next;
	    	}
    	}
		
    }
	
	//return the minimum value of the list
	public int minData() {
    	
    	if(head == null) {
			System.out.println("Impossible to return the minimum value of the list");
			return -1;
		}
    	else {
    		
        	LinkedList cp1 = this.copy();
        	cp1.orderData();
        	return cp1.getFirstData();
    	}
		
    }
	
	//return the minimum node of the list
	public Node minNode() {
	    	
		if(head == null) {
			System.out.println("Impossible to return the minimum node of the list");
			return null;
		}
	    else {
	    	
	        Node app = head;
	        Node min = head;
	        
	        while(app != null) {
	        		
				if(min.data > app.data)
	        		min = app;
					
	        	app = app.next;
	        }
				
	        return min;
	    }
			
	}
	
	//return the maximum value of the list
	public int maxData() {
    	
    	if(head == null) {
			System.out.println("Impossible to return the maximum value of the list");
			return -1;
		}
    	else {
			
    		LinkedList cp1 = this.copy();
        	cp1.orderData();
        	return cp1.getLastData();
    	}
		
    }
	
	//return the maximum node of the list
	public Node maxNode() {
	    	
		if(head == null) {
			System.out.println("Impossible to return the maximum node of the list");
			return null;
		}
	    else {
				
	        Node app = head;
	        Node max = head;
	        	
	        while(app != null) {
					
	        	if(max.data < app.data)
	        		max = app;
	        		
				app = app.next;
	        }
				
	        return max;
	    }
			
	}
	
	//return a list with all the common elements (picked one time) from l1 and l2
    public LinkedList intersection(LinkedList secondList) {
    	
    	if(head == null || secondList == null)
    		return null;
    	else {
    		
    		LinkedList thirdList = new LinkedList();
    		
    		if(this.size() <= secondList.size()) {
    		
    			Node app = head;
    			
    			while(app != null) {
    				
    				if(secondList.exist(app.data) && !thirdList.exist(app.data))
    					thirdList.insertAsFirst(app.data);
    				
    				app = app.next;
    			}
    			
    		}
    		else {
        		
    			Node app = secondList.head;
    			
    			while(app != null) {
    				
    				if(this.exist(app.data) && !thirdList.exist(app.data))
    					thirdList.insertAsFirst(app.data);
    				
    				app = app.next;
    			}
    		}
			
    		return thirdList;
    	}
		
    }
	
	//return a list with all the elements (picked one time) existing in l1 and l2
    public LinkedList union(LinkedList secondList) {
    	
    	if(head == null || secondList == null)
    		return null;
    	else {
    		
    		LinkedList thirdList = new LinkedList();
    		Node firstNode = head;
			
    		while(firstNode != null) {
				
				if(!thirdList.exist(firstNode.data))
					thirdList.insertAsFirst(firstNode.data);
				
				firstNode = firstNode.next;
			}
    		
			Node secondNode = secondList.head;
			
			while(secondNode != null) {
				
				if(!thirdList.exist(secondNode.data))
					thirdList.insertAsFirst(secondNode.data);
				
				secondNode = secondNode.next;
			}
			
    		return thirdList;
    	}
		
    }
	/* --------------------------------- */
	
    
}
