 # Dijkstra (다익스트라)
 > + 그래프에서 한 노드에서 다른 노드까지의 ``최단경로``를 구하는 알고리즘      
 > + 다이나믹 프로그래밍을 활용한 대표적인 ``최단경로탐색 알고리즘`` -> 현재까지 알고 있던 최단 경로를 계속 갱신      
 > + weigt가 **음수인 것은 허용되지 않는다**.    
 > + **cycle은 허용**된다.         
 > + 최단경로를 구하는 알고리즘에는 **벨만-포드, 프로디드 워샬 알고리즘**도 존재         
 
 ## 순차탐색
 > 방문하지 않은 노드 중 거리값이 가장 작은 노드를 선택해 다음 탐색 노드를 선택
 
 ## 작동 과정
 1. 출발 노드와 도착 노드를 설정
 2. 최단거리를 저장하는 배열을 초기화 (무한으로)
 3. 현재 위치한 노드의 인접 노드 중 방문하지 않은 노드를 구별,
    방문하지 않은 노드 중 거리가 짧은 노드를 선택하고 방문 처리
 4. 해당 노드를 거쳐 다른 노드로 가는 weight를 계산해 최단거리를 업데이트
 5. 3과 4번 과정 반복

예시)       
![image](https://user-images.githubusercontent.com/104772331/211724409-80bf614e-6e6b-4966-9b04-065f6a47c064.png)     
-> 무한으로 초기화 , 출발노드 : 1 , 도착노드 : 6
![image](https://user-images.githubusercontent.com/104772331/211724533-595fe184-f8ab-4ca7-9941-e851e24129a8.png)        
-> 출발노드를 0으로 초기화    
![image](https://user-images.githubusercontent.com/104772331/211724579-90cd7886-a711-4a28-9336-034bf92cc674.png)           
-> 인접한 노드 중 방문하지 않은 노드의 거리값을 비교해 업데이트      
-> 방문하지 않은 노드 중 거리값이 작은 노드를 선택 (4번 노드 선택)          
-> 1 노드는 방문처리               
![image](https://user-images.githubusercontent.com/104772331/211724993-2aa2aee4-4aa6-4656-ae03-c634b3a3a0f4.png)       
-> 4번과 연결된 2,5번까지 오는 거리 계산 후 비교            
-> 방문하지 않은 노드 중 거리값이 작은 노드 선택(2번이나 5번 노드 선택)   
-> 이후는 똑같은 과정 반복            
<img src = "https://user-images.githubusercontent.com/104772331/211851517-45ab8bbc-6e81-429a-9cd7-bea0605c9a5b.png" width="700" height="600"/> 
-> 최종 결과값         

 ## 우선순위 큐(priority Queue)를 활용
 > + 순차 탐색을 사용하는 경우 시간이 오래 걸릴 수 있는 점을 개선        
 > + 최소 거리 값을 우선순위로 가지는 ``priority queue``를 활용.          
 > + ``-``를 붙여 가까운 거리가 가장 앞에 오도록 한다.  
 > + 시작노드로부터 **가장 가까운 노드가 우선순위**가 된다.    
 > + 방문 여부를 기록할 필요가 없다.      
 
 ## 작동 과정 
 1. 최단 거리를 초기화(무한으로)
 2. 출발 노드를 설정
 3. 최소거리가 되면 priority queue에 저장하면서 지금까지의 거리와 비교하면서 업데이트
 4. priority queue가 빌 때까지 반복

예시)        
<img src = "https://user-images.githubusercontent.com/104772331/211726622-72ab7a34-66bf-4971-9566-2feaf04bfe70.png" width="600" height="600"/>     
-> 시작노드의 거리를 업데이트                
-> priority queue에 저장       
![image](https://user-images.githubusercontent.com/104772331/211726727-b4303097-bed5-4ff5-b8c1-9527f3305880.png)          
-> queue에서 꺼내어 인접한 노드를 봄                
-> 거리값이 작으면 업데이트하고, 큐에 저장        
![image](https://user-images.githubusercontent.com/104772331/211727108-1a34a30e-a8d4-4fda-afba-74241c43863a.png)           
-> 노드를 꺼내서 인접 노드를 조사           
-> 위에서와 같이 거리값이 작으면 업데이트하고, 큐에 저장            
-> 4에서 2로 가는 경우 3이기 때문에 업데이트를 하지 않고, 큐에도 저장하지 않음.             
![image](https://user-images.githubusercontent.com/104772331/211727680-3c26dcb6-c087-461f-8f8e-ecd5d760425e.png)
![image](https://user-images.githubusercontent.com/104772331/211727713-e7b64de6-6f8b-4ca0-b921-c6de3d424061.png)
![image](https://user-images.githubusercontent.com/104772331/211727734-895293b1-cf19-4803-b8dc-a3d08bc3d556.png)
![image](https://user-images.githubusercontent.com/104772331/211727766-4c75eb8a-bc37-4fb1-b15e-0b462db9a428.png)

+ 참고블로그  <https://velog.io/@717lumos/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BCDijkstra-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98>
