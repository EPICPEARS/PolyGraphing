#include <polysolve.hpp>


void PolyNomialSolver::GetPoints(SDL_Renderer *rend){
    long double increment = 20.0/this->detail;
    double starting_point = -10;
    double x_pos = starting_point;
    int counter;
    double previous_function_result, previous_x_pos, function_result;


   SDL_SetRenderDrawColor(rend, 0, 250, 250, 100);

    previous_x_pos = starting_point;
    

    for(int x=0; x < this->poly_degree + 1; x++){
    previous_function_result = this->terms[x] * pow(x_pos, this->poly_degree - x) + previous_function_result;
    }

    
    for (counter=0; counter<=detail; counter++){
        function_result = 0;
        double first_num = this->terms[0] * pow(x_pos, 2);
        double second_num = this->terms[1] * x_pos;

        for (int j=0; j<this->poly_degree + 1; j++){
            
            function_result = function_result + this->terms[j] * pow(x_pos, this->poly_degree - j);
        }

        cout << function_result << endl;

        SDL_RenderDrawLine(rend, float(15 * previous_x_pos + 300), float(-10 * previous_function_result + 200), float(15 * x_pos + 300), float(-10 * function_result + 200));
        
        
        previous_x_pos = x_pos;
        previous_function_result = function_result;
        x_pos = x_pos + increment;
    }
    
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 100);
}



PolyNomialSolver::PolyNomialSolver(int argc, char *argv[]){

    this->terms = new int(argc - 2);
    for (int k=2; k < argc; k++){
        this->terms[k-2] = strtol(argv[k], NULL, 10);
    }

    this->poly_degree = strtol(argv[1], NULL, 10);

}

void PolyNomialSolver::RealRoots(){

    int b_squared = pow(this->terms[1], 2);
    int discrim = b_squared - (4 * this->terms[0] * this->terms[2]);

    if (discrim < 0){
        this->roots[0] = NULL;

    }else if (discrim == 0) {
        double result = (-1 * this->terms[1])/(2 * this->terms[0]);
        this->roots[0] = result;

    }else if (discrim > 0 ){
        double denom = (2 * this->terms[0]);
        double not_discrim  = (-1 * this->terms[1]);
        double root_discrim = sqrt(discrim);

        double first_result = (not_discrim + root_discrim)/denom;
        double second_result = (not_discrim - root_discrim)/denom;

        this->roots[0] = first_result;
        this->roots[1] = second_result;

    }
}

void PolyNomialSolver::PrintRoots(){
    cout << this->roots[0] << endl;
    cout << this->roots[1] << endl;
}
