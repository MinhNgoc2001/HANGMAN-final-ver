#include <bits/stdc++.h>
#include <SDL.h>
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "HANGMAN";

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();
vector <string> words;
string answer,s;
int a,b,cnt;
void loadwordsdata(){
    ifstream fin2("HANGMANWORDS.inp",ios::in);
    fin2 >> a;
    for(int i=0;i<a;i++){
        fin2 >> s;
        words.push_back(s);
    }
    fin2.close();
}
void pickwords(){
    srand(time(NULL));
    b=rand();
    b=b%a;
    answer=words[b];
}
int main(int argc, char* argv[])
{
    cout << "Welcome to HANGMAN" << '\n' << "Input p to play" << '\n' << "or e to Exit" << endl;
    char startend;
    cin >> startend;
    if(startend =='e')
        exit(0);
    loadwordsdata();
    pickwords();
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);
    SDL_Rect filled_rect;
    filled_rect.x = 0;
    filled_rect.y = 0;
    filled_rect.w = SCREEN_WIDTH;
    filled_rect.h = SCREEN_HEIGHT;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &filled_rect);
    // Fill white window

    int match; char guess;
    string progress="";
    for(int i=0;i<answer.length();i++)
        progress=progress+'-';
    while(cnt<=7){
        int loseornot=0;
        for(int i=0;i<progress.length();i++)
            if(progress[i]=='-')
                loseornot++;
        if(!loseornot){
            cout << "You Won !!!" << endl;
            cout << "The Answer was " << answer << '.' <<endl;
            waitUntilKeyPressed();
            exit(0);
        }
        cout << progress << endl;
        SDL_RenderPresent(renderer);
        match=0;
        if(cnt==7){
            cout << "You Lose" << endl;
            cout << "The Answer was " << answer << '.' << endl;
            waitUntilKeyPressed();
            exit(0);
        }
        cout << "GUESS A WORD." << endl;
        cin >> guess;
        for(int i=0;i<answer.length();i++)
            if(answer[i]==guess){
                progress[i]=guess;
                match++;
            }
        if(match==0){
            cout << "There was no " << guess << "." << endl;
            cnt++;
            if(cnt==7){
                filled_rect.x = 398;
                filled_rect.y = 0;
                filled_rect.w = 4;
                filled_rect.h = 100;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderFillRect(renderer, &filled_rect);
                //Draw rope
            }
            if(cnt==1){
                filled_rect.x = 360;
                filled_rect.y = 100;
                filled_rect.w = 80;
                filled_rect.h = 80;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderFillRect(renderer, &filled_rect);
                //Draw head
            }
            if(cnt==2){
                filled_rect.x = 380;
                filled_rect.y = 185;
                filled_rect.w = 40;
                filled_rect.h = 150;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderFillRect(renderer, &filled_rect);
                //Draw Body
            }
            if(cnt==3){
                filled_rect.x = 345;
                filled_rect.y = 190;
                filled_rect.w = 20;
                filled_rect.h = 120;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderFillRect(renderer, &filled_rect);
                //Draw right arm
            }
            if(cnt==4){
                filled_rect.x = 435;
                filled_rect.y = 190;
                filled_rect.w = 20;
                filled_rect.h = 120;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderFillRect(renderer, &filled_rect);
                //Draw left arm
            }
            if(cnt==5){
                filled_rect.x = 355;
                filled_rect.y = 340;
                filled_rect.w = 30;
                filled_rect.h = 180;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderFillRect(renderer, &filled_rect);
                //Draw right leg
            }
            if(cnt==6){
                filled_rect.x = 415;
                filled_rect.y = 340;
                filled_rect.w = 30;
                filled_rect.h = 180;
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                SDL_RenderFillRect(renderer, &filled_rect);
                //Draw left leg
            }
        }
        else
            cout << "There was " << match << ' ' << guess << '.' << endl;
    }
}
void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thông thường chạy với môi trường bình thường ở nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
    //Khi chạy ở máy thực hành WinXP ở trường (máy ảo)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
