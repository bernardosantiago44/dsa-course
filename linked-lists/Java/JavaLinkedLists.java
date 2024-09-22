public class JavaLinkedLists {
    public static void main(String[] args) {
        MyLinkedList list = new MyLinkedList();
        list.insertfirst(15);
        list.insertfirst(11);
        list.insertfirst(9);
        list.insertfirst(4);
        list.insertfirst(1);

        /* 
        try {
            System.out.println(list.first());
        } catch (Exception e) {
            System.out.println("The list is empty.");
        }
        */
        list.print();
    }
}
