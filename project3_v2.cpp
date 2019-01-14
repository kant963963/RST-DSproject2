class Student{
    public:
        void makeMove(int Record[5][6], int Max[5][6], Color color[5][6], Color inputColor){
            int i;
            int j;
            bool k=false;
            Color rivalColor;

            if(inputColor == Red) rivalColor = Blue;
            else if(inputColor == Blue) rivalColor = Red;

            if(color[0][0] == White) {x = 0;y = 0; return;}
            else if(color[4][5] == White) {x = 4;y = 5; return;}
            else if(color[4][0] == White) {x = 4;y = 0; return;}
            else if(color[0][5] == White) {x = 0;y = 5; return;}

            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(i == 0){
                    if(color[i][j] == inputColor && Record[i][j] == Max[i][j] -1){
                        if((color[i+1][j] == rivalColor && Record[i+1][j] == Max[i+1][j] -1)||
                           (color[i][j+1] == rivalColor && Record[i][j+1] == Max[i][j+1] -1)||
                           (color[i][j-1] == rivalColor && Record[i][j-1] == Max[i][j-1] -1)){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(j == 0){
                    if(color[i][j] == inputColor && Record[i][j] == Max[i][j] -1){
                        if((color[i+1][j] == rivalColor && Record[i+1][j] == Max[i+1][j] -1)||
                           (color[i-1][j] == rivalColor && Record[i-1][j] == Max[i-1][j] -1)||
                           (color[i][j+1] == rivalColor && Record[i][j+1] == Max[i][j+1] -1)){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(j == 5){
                    if(color[i][j] == inputColor && Record[i][j] == Max[i][j] -1){
                        if((color[i+1][j] == rivalColor && Record[i+1][j] == Max[i+1][j] -1)||
                           (color[i-1][j] == rivalColor && Record[i-1][j] == Max[i-1][j] -1)||
                           (color[i][j-1] == rivalColor && Record[i][j-1] == Max[i][j-1] -1)){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(i == 4){
                    if(color[i][j] == inputColor && Record[i][j] == Max[i][j] -1){
                        if((color[i-1][j] == rivalColor && Record[i-1][j] == Max[i-1][j] -1)||
                           (color[i][j+1] == rivalColor && Record[i][j+1] == Max[i][j+1] -1)||
                           (color[i][j-1] == rivalColor && Record[i][j-1] == Max[i][j-1] -1)){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }

                else if(color[i][j] == inputColor && Record[i][j] == Max[i][j] -1){
                    if((color[i+1][j] == rivalColor && Record[i+1][j] == Max[i+1][j] -1)|| (color[i-1][j] == rivalColor && Record[i-1][j] == Max[i-1][j] -1)||
                       (color[i][j+1] == rivalColor && Record[i][j+1] == Max[i][j+1] -1)|| (color[i][j-1] == rivalColor && Record[i][j-1] == Max[i][j-1] -1)){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                    if((color[i+1][j] == rivalColor && (Max[i+1][j] - Record[i+1][j]) < (Max[i][j] - Record[i][j]))||
                       (color[i-1][j] == rivalColor && (Max[i-1][j] - Record[i-1][j]) < (Max[i][j] - Record[i][j]))||
                       (color[i][j+1] == rivalColor && (Max[i][j+1] - Record[i][j+1]) < (Max[i][j] - Record[i][j]))||
                       (color[i][j-1] == rivalColor && (Max[i][j-1] - Record[i][j-1]) < (Max[i][j] - Record[i][j]))){
                        k = true;
                    }
                    if(k == false){
                        if(i != 4 && color[i+1][j] == rivalColor && (Max[i+1][j] - Record[i+1][j]) == (Max[i][j] - Record[i][j])){
                            if((color[i+2][j] == inputColor   && Record[i+2][j]   == Max[i+2][j]   -1 && i != 3)||
                               (color[i+1][j+1] == inputColor && Record[i+1][j+1] == Max[i+1][j+1] -1 && j != 5)||
                               (color[i+1][j-1] == inputColor && Record[i+1][j-1] == Max[i+1][j-1] -1 && j != 0)){
                                k = true;
                            }
                            else{
                                x = i;
                                y = j;
                                return;
                            }
                        }
                        if(i != 0 && color[i-1][j] == rivalColor && (Max[i-1][j] - Record[i-1][j]) == (Max[i][j] - Record[i][j])){
                            if((color[i-2][j] == inputColor   && Record[i-2][j]   == Max[i-2][j]   -1 && i != 1)||
                               (color[i-1][j+1] == inputColor && Record[i-1][j+1] == Max[i-1][j+1] -1 && j != 5)||
                               (color[i-1][j-1] == inputColor && Record[i-1][j-1] == Max[i-1][j-1] -1 && j != 0)){
                                k = true;
                            }
                            else{
                                x = i;
                                y = j;
                                return;
                            }
                        }
                        if(j != 5 && color[i][j+1] == rivalColor && (Max[i][j+1] - Record[i][j+1]) == (Max[i][j] - Record[i][j])){
                            if((color[i][j+2] == inputColor   && Record[i][j+2]   == Max[i][j+2]   -1 && j != 4)||
                               (color[i+1][j+1] == inputColor && Record[i+1][j+1] == Max[i+1][j+1] -1 && i != 4)||
                               (color[i-1][j+1] == inputColor && Record[i-1][j+1] == Max[i-1][j+1] -1 && i != 0)){
                                k = true;
                            }
                            else{
                                x = i;
                                y = j;
                                return;
                            }
                        }
                        if(j != 0 && color[i][j-1] == rivalColor && (Max[i][j-1] - Record[i][j-1]) == (Max[i][j] - Record[i][j])){
                            if((color[i][j-2] == inputColor   && Record[i][j-2]   == Max[i][j-2]   -1 && j != 1)||
                               (color[i+1][j-1] == inputColor && Record[i+1][j-1] == Max[i+1][j-1] -1 && i != 4)||
                               (color[i-1][j-1] == inputColor && Record[i-1][j-1] == Max[i-1][j-1] -1 && i != 0)){
                                k = true;
                            }
                            else{
                                x = i;
                                y = j;
                                return;
                            }
                        }
                    }
                    k = false;
                }
            }

            for(j=0;j<6;j++){
                i = 0;
                if(color[i][j] == White && Record[i][j] < Max[i][j] -1){
                    if(Record[i+1][j] <= 1 && color[i][j+1] == White && color[i][j-1] == White){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++){
                j = 0;
                if(color[i][j] == White && Record[i][j] < Max[i][j] -1){
                    if(color[i+1][j] == White && Record[i][j+1] <= 1 && color[i-1][j] == White){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++){
                j = 5;
                if(color[i][j] == White && Record[i][j] < Max[i][j] -1){
                    if(color[i+1][j] == White && color[i-1][j] == White && Record[i][j-1] <= 1){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(j=0;j<6;j++){
                i = 4;
                if(color[i][j] == White && Record[i][j] < Max[i][j] -1){
                    if(Record[i-1][j] <= 1 && color[i][j+1] == White && color[i][j-1] == White){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(i == 0){
                    if(color[i][j] == White && Record[i][j] < Max[i][j] -1){
                        if(color[i+1][j] == White && color[i][j+1] == White && color[i][j-1] == White){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(j == 0){
                    if(color[i][j] == White && Record[i][j] < Max[i][j] -1){
                        if(color[i+1][j] == White && color[i-1][j] == White && color[i][j+1] == White){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(j == 5){
                    if(color[i][j] == White && Record[i][j] < Max[i][j] -1){
                        if(color[i+1][j] == White && color[i-1][j] == White && color[i][j-1] == White){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(i == 4){
                    if(color[i][j] == White && Record[i][j] < Max[i][j] -1){
                        if(color[i-1][j] == White && color[i][j+1] == White && color[i][j-1] == White){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(color[i][j] == White && Record[i][j] < Max[i][j] -1){
                    if(color[i+1][j] == White && color[i-1][j] == White && color[i][j+1] == White && color[i][j-1] == White){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(j=0;j<6;j++){
                i = 0;
                if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                    if(Record[i+1][j] <= 1 && color[i][j+1] == White && color[i][j-1] == White){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++){
                j = 0;
                if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                    if(color[i+1][j] == White && Record[i][j+1] <= 1 && color[i-1][j] == White){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++){
                j = 5;
                if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                    if(color[i+1][j] == White && color[i-1][j] == White && Record[i][j-1] <= 1){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(j=0;j<6;j++){
                i = 4;
                if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                    if(Record[i-1][j] <= 1 && color[i][j+1] == White && color[i][j-1] == White){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(i == 0){
                    if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                        if(color[i+1][j] == White && color[i][j+1] == White && color[i][j-1] == White){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(j == 0){
                    if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                        if(color[i+1][j] == White && color[i-1][j] == White && color[i][j+1] == White){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(j == 5){
                    if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                        if(color[i+1][j] == White && color[i-1][j] == White && color[i][j-1] == White){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(i == 4){
                    if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                        if(color[i-1][j] == White && color[i][j+1] == White && color[i][j-1] == White){
                            x = i;
                            y = j;
                            return;
                        }
                    }
                }
                else if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                    if(color[i+1][j] == White && color[i-1][j] == White && color[i][j+1] == White && color[i][j-1] == White){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }

            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(color[i][j] == White){
                    if((color[i+1][j] == rivalColor && Max[i+1][j]-1 == Record[i+1][j])||
                       (color[i-1][j] == rivalColor && Max[i-1][j]-1 == Record[i-1][j])||
                       (color[i][j+1] == rivalColor && Max[i][j+1]-1 == Record[i][j+1])||
                       (color[i][j-1] == rivalColor && Max[i][j-1]-1 == Record[i][j-1])){
                        k = true;
                    }
                    if(k == false){
                        x = i;
                        y = j;
                        return;
                    }
                    k = false;
                }
            }

            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(color[i][j] == White){
                    x = i;
                    y = j;
                    return;
                }
            }
            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                    if((color[i+2][j]   == rivalColor && color[i+1][j]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i+1][j] - Record[i+1][j] + Max[i+2][j] - Record[i+2][j]))||
                       (color[i-2][j]   == rivalColor && color[i-1][j]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i-1][j] - Record[i-1][j] + Max[i-2][j] - Record[i-2][j]))||
                       (color[i][j+2]   == rivalColor && color[i][j+1]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i][j+1] - Record[i][j+1] + Max[i][j+2] - Record[i][j+2]))||
                       (color[i][j-2]   == rivalColor && color[i][j-1]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i][j-1] - Record[i][j-1] + Max[i][j-2] - Record[i][j-2]))){
                        x = i;
                        y = j;
                        return;
                    }
                    else if(color[i+1][j+1] == rivalColor &&
                           ((color[i+1][j]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i+1][j] - Record[i+1][j] + Max[i+1][j+1] - Record[i+1][j+1]))||
                           (color[i][j+1]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i][j+1] - Record[i][j+1] + Max[i+1][j+1] - Record[i+1][j+1])))){
                        x = i;
                        y = j;
                        return;
                    }
                    else if(color[i+1][j-1] == rivalColor &&
                            ((color[i+1][j]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i+1][j] - Record[i+1][j] + Max[i+1][j-1] - Record[i+1][j-1]))||
                            (color[i][j-1]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i][j-1] - Record[i][j-1] + Max[i+1][j-1] - Record[i+1][j-1])))){
                        x = i;
                        y = j;
                        return;
                    }
                    else if(color[i-1][j+1] == rivalColor &&
                            ((color[i-1][j]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i-1][j] - Record[i-1][j] + Max[i-1][j+1] - Record[i-1][j+1]))||
                            (color[i][j+1]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i][j+1] - Record[i][j+1] + Max[i-1][j+1] - Record[i-1][j+1])))){
                        x = i;
                        y = j;
                        return;
                    }
                    else if(color[i-1][j-1] == rivalColor &&
                            ((color[i-1][j]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i-1][j] - Record[i-1][j] + Max[i-1][j-1] - Record[i-1][j-1]))||
                            (color[i][j-1]   == inputColor && (Max[i][j] - Record[i][j]) <= (Max[i][j-1] - Record[i][j-1] + Max[i-1][j-1] - Record[i-1][j-1])))){
                        x = i;
                        y = j;
                        return;
                    }
                }
            }
            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(color[i][j] == inputColor && Record[i][j] < Max[i][j] -1){
                    x = i;
                    y = j;
                    return;
                }
            }
            for(i=0;i<5;i++) for(j=0;j<6;j++){
                if(color[i][j] == inputColor && Record[i][j] == Max[i][j] -1){
                    x = i;
                    y = j;
                    return;
                }
            }

        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
    private:
        int x;
        int y;
    };
