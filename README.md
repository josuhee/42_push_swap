<hr/>  
<h3 align="center">🌱 42_push_swap 🌱</h3>  
<hr/>  

<img width="256" alt="Screen Shot 2021-06-17 at 8 49 39 PM" src="https://user-images.githubusercontent.com/69746967/122391066-99b50000-cfad-11eb-9c4a-09e8d6a4ae7d.png">

### 📌 Goal  
* 스택에 있는 인자들을 아래 operation을 사용하여 정렬할 것.

### 📌 Operation
- sa : 스택 a의 상단 2개의 원소를 swap. 단, 원소가 1개 이하면 작동 x
- sb : 스택 b의 상단 2개의 원소를 swap. 단, 원소가 1개 이하면 작동 x
- ss : sa, sb 동시 사용
- pa : 스택 b의 top원소를 스택 a에 푸쉬. 단, 원소가 없다면 작동 x
- pb : 스택 a의 top원소를 스택 b에 푸쉬. 단, 원소가 없다면 작동 x
- ra : 스택 a의 모든 원소들을 shift up. top 원소가 제일 하단으로.
- rb : 스택 b의 모든 원소들을 shift up. top 원소가 제일 하단으로.
- rr : ra, rb 동시 사용.
- rra : 스택 a의 모든 원소들을 shift down. 제일 하단에 있던 원소가 top로.
- rrb : 스택 b의 모든 원소들을 shift down. 제일 하단에 있던 원소가 top로.
- rrr : rra, rrb 동시 사용.
  
### 📌 Error
- 정수가 아님
- int의 범위를 넘음
- 중복된 숫자.

### 📌 Bonus
* checker 구현하기

### 📌 Evaluation
#### ⚔ Middle version ⚔
> If the following test fails, no points will be awarded for this section. Move to the next one. Move to the next one. Use the cheacker binary given on the attachments.
> Run "$>ARG="<100 random values>", ./push_swap $ARG | ./checker_OS $ARG" and replace the placeholder by 100 random valid values. Check that the checker program displays "OK" and that the size of the list instuctions.
> Give points in accordance :
> - less than 700 : 5
> - less than 900 : 4
> - less than 1100 : 3
> - less than 1300 : 2
> - less than 1500 : 1  

#### ⚔ Advanced version ⚔
> If the following test fails, no points will be awarded for this section. Move to the next one. Move to the next one. Use the cheacker binary given on the attachments.
> Run "$>ARG="<500 random values>", ./push_swap $ARG | ./checker_OS $ARG" and replace the placeholder by 100 random valid values. Check that the checker program displays "OK" and that the size of the list instuctions.
> Give points in accordance :
> - less than 5500 : 5
> - less than 7000 : 4
> - less than 8500 : 3
> - less than 10000 : 2
> - less than 11500 : 1  
