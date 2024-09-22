import java.util.EmptyStackException;

public class MyLinkedList {
    private NodeLL head, 
                   tail;
    private int size; 
    
    public MyLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }
    
    public int length() {
        return this.size;
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public int first() throws Exception {
        if (this.isEmpty()) {
            throw new EmptyStackException();
        }
        return this.head.getVal();
    }

    public int last() throws Exception {
        if (this.isEmpty()) {
            throw new EmptyStackException();
        }
        return this.tail.getVal();
    }

    public void insertfirst(int value) {
        NodeLL newNode = new NodeLL(value, this.head);
        this.head = newNode;
        if (this.isEmpty()) {
            this.tail = newNode;
        }
        this.size++;
    }

    public void print() {
        if (this.isEmpty()) return;
        NodeLL current = head;
        while (current != null) {
            System.out.print(current.getVal());
            if (current.getNext() != null) {
                System.out.print(" -> ");
            }
            current = current.getNext();
        }
        System.out.println("");
    }
}
