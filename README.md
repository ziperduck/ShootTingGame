# ShooTingGame

Developed with Unreal Engine 4

해야하는 일

오브젝트들에게 Actions값들을 전달해줄 클래스가 필요하다

키보드 값을 가지고 Actions값을 전달해줘야한다.

Actions들의 움직임을 만들어야한다.

완료한 한일

Object라는 이동가능한 물체들의 정보를 가지고있는 추상 클래스를 정의했다
Object를 상속받은 PlayerCharacter를 파생 클래스를 정의했다.

Actions라는 Object의 행동들을 제어하는 추상 클래스를 정의했다.
Object를 상속받은 Object의 움직인에 제어하는 Move_ 파생 클래스를 정의했다.