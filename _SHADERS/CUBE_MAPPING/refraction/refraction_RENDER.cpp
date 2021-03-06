    glUseProgram(refraction_SHADER);      
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                  
    glEnableVertexAttribArray(1);    
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);                                                                                                                                                
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__UNIFORMS          
    glUniform4f(UNIFORM_LIGHT_POSITION_01_refraction, refraction_LIGHT_POSITION_01[0], refraction_LIGHT_POSITION_01[1], refraction_LIGHT_POSITION_01[2], refraction_LIGHT_POSITION_01[3]);        
    glUniform1f(UNIFORM_SHININESS_refraction, refraction_SHININESS);                                                                                                                  
    glUniform1f(UNIFORM_ATTENUATION_refraction, refraction_ATTENUATION);                                                                                                                  
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_refraction,   1,0,  mvpMatrix);                                                                                                      
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_refraction,    1,0,  lightMatrix);                                                                                                    
    glUniform1i (UNIFORM_TEXTURE_DOT3_refraction, 1);      
    glUniform1i (UNIFORM_TEXTURE_refraction, 0 );  
    
    CUBE_MAPPING_textureID = glGetUniformLocation(refraction_SHADER, "EnvMap"); 
    glUniform1i(CUBE_MAPPING_textureID, 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,  cubemapTexture[0]); 
