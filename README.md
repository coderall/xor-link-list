# xor-link-list
a simple xor-link-list implementation

  a xor-link-list is a special double-linked list within one pointer not the normal implementation with two pointers.it uses the xor instruction to determine the next or the prev node.it only support iteration from head to tail or from tail to head,not from the middle point.
  
  Chinese:
（1）通过代码可以知道，这种链表节省了空间，但是只支持从前向和后向迭代访问，不支持从中间节点开始访问

（2）代码只演示了简单的思想，没有考虑其他复杂场景，也没有进行封装

（3）理解思想就好，不建议平常使用，代码可读性不高

（4）代码中有内存泄漏（厚脸皮，就不回收了）

（5）可以联想内核中的红黑树实现，在指针的最后一位保存节点的颜色数值，减少节点占用空间

（6）欢迎交流，指正
