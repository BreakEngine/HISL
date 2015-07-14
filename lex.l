%{
#include <string>
#include "Node.h"
#include "parser.hpp"
#include <iostream>
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
%}


%%
"return"                  {return RETURN;}         //return keyword
"void"                    {SAVE_TOKEN; return TYPE;}
"int"                     {SAVE_TOKEN; return TYPE;}
"float"                   {SAVE_TOKEN; return TYPE;}
"vec2"                    {SAVE_TOKEN; return TYPE;}
"vec3"                    {SAVE_TOKEN; return TYPE;}
"vec4"                    {SAVE_TOKEN; return TYPE;}
"bvec2"                   {SAVE_TOKEN; return TYPE;}
"bvec3"                   {SAVE_TOKEN; return TYPE;}
"bvec4"                   {SAVE_TOKEN; return TYPE;}
"ivec2"                   {SAVE_TOKEN; return TYPE;}
"ivec3"                   {SAVE_TOKEN; return TYPE;}
"ivec4"                   {SAVE_TOKEN; return TYPE;}
"mat2"                    {SAVE_TOKEN; return TYPE;}
"mat3"                    {SAVE_TOKEN; return TYPE;}
"mat4"                    {SAVE_TOKEN; return TYPE;}
"sampler2D"               {SAVE_TOKEN; return TYPE;}
"samplerCube"             {SAVE_TOKEN; return TYPE;}
"true"                    {SAVE_TOKEN; return BOOLCONST;}
"false"                   {SAVE_TOKEN; return BOOLCONST;}
"mat2x2"                  {SAVE_TOKEN; return TYPE;}
"mat2x3"                  {SAVE_TOKEN; return TYPE;}
"mat2x4"                  {SAVE_TOKEN; return TYPE;}
"mat3x2"                  {SAVE_TOKEN; return TYPE;}
"mat3x3"                  {SAVE_TOKEN; return TYPE;}
"mat3x4"                  {SAVE_TOKEN; return TYPE;}
"mat4x2"                  {SAVE_TOKEN; return TYPE;}
"mat4x3"                  {SAVE_TOKEN; return TYPE;}
"mat4x4"                  {SAVE_TOKEN; return TYPE;}
"dmat2"                   {SAVE_TOKEN; return TYPE;}
"dmat3"                   {SAVE_TOKEN; return TYPE;}
"dmat4"                   {SAVE_TOKEN; return TYPE;}
"dmat2x2"                 {SAVE_TOKEN; return TYPE;}
"dmat2x3"                 {SAVE_TOKEN; return TYPE;}
"dmat2x4"                 {SAVE_TOKEN; return TYPE;}
"dmat3x2"                 {SAVE_TOKEN; return TYPE;}
"dmat3x3"                 {SAVE_TOKEN; return TYPE;}
"dmat3x4"                 {SAVE_TOKEN; return TYPE;}
"dmat4x2"                 {SAVE_TOKEN; return TYPE;}
"dmat4x3"                 {SAVE_TOKEN; return TYPE;}
"dmat4x4"                 {SAVE_TOKEN; return TYPE;}
"image1D"                 {SAVE_TOKEN; return TYPE;}
"iimage1D"                {SAVE_TOKEN; return TYPE;}
"uimage1D"                {SAVE_TOKEN; return TYPE;}
"image2D"                 {SAVE_TOKEN; return TYPE;}
"iimage2D"                {SAVE_TOKEN; return TYPE;}
"uimage2D"                {SAVE_TOKEN; return TYPE;}
"image3D"                 {SAVE_TOKEN; return TYPE;}
"iimage3D"                {SAVE_TOKEN; return TYPE;}
"uimage3D"                {SAVE_TOKEN; return TYPE;}
"image2DRect"             {SAVE_TOKEN; return TYPE;}
"iimage2DRect"            {SAVE_TOKEN; return TYPE;}
"uimage2DRect"            {SAVE_TOKEN; return TYPE;}
"imageCube"               {SAVE_TOKEN; return TYPE;}
"iimageCube"              {SAVE_TOKEN; return TYPE;}
"uimageCube"              {SAVE_TOKEN; return TYPE;}
"imageBuffer"             {SAVE_TOKEN; return TYPE;}
"iimageBuffer"            {SAVE_TOKEN; return TYPE;}
"uimageBuffer"            {SAVE_TOKEN; return TYPE;}
"image1DArray"            {SAVE_TOKEN; return TYPE;}
"iimage1DArray"           {SAVE_TOKEN; return TYPE;}
"uimage1DArray"           {SAVE_TOKEN; return TYPE;}
"image2DArray"            {SAVE_TOKEN; return TYPE;}
"iimage2DArray"           {SAVE_TOKEN; return TYPE;}
"uimage2DArray"           {SAVE_TOKEN; return TYPE;}
"imageCubeArray"          {SAVE_TOKEN; return TYPE;}
"iimageCubeArray"         {SAVE_TOKEN; return TYPE;}
"uimageCubeArray"         {SAVE_TOKEN; return TYPE;}
"image2DMS"               {SAVE_TOKEN; return TYPE;}
"double"                  {SAVE_TOKEN; return TYPE;}
"dvec2"                   {SAVE_TOKEN; return TYPE;}
"dvec3"                   {SAVE_TOKEN; return TYPE;}
"dvec4"                   {SAVE_TOKEN; return TYPE;}
"samplerCubeArray"        {SAVE_TOKEN; return TYPE;}
"samplerCubeArrayShadow"  {SAVE_TOKEN; return TYPE;}
"isamplerCubeArray"       {SAVE_TOKEN; return TYPE;}
"usamplerCubeArray"       {SAVE_TOKEN; return TYPE;}
"sampler1DArrayShadow"    {SAVE_TOKEN; return TYPE;}
"isampler1DArray"         {SAVE_TOKEN; return TYPE;}
"usampler1D"              {SAVE_TOKEN; return TYPE;}
"isampler1D"              {SAVE_TOKEN; return TYPE;}
"usampler1DArray"         {SAVE_TOKEN; return TYPE;}
"samplerBuffer"           {SAVE_TOKEN; return TYPE;}
"uint"                    {SAVE_TOKEN; return TYPE;}
"uvec2"                   {SAVE_TOKEN; return TYPE;}
"uvec3"                   {SAVE_TOKEN; return TYPE;}
"uvec4"                   {SAVE_TOKEN; return TYPE;}
"samplerCubeShadow"       {SAVE_TOKEN; return TYPE;}
"sampler2DArray"          {SAVE_TOKEN; return TYPE;}
"sampler2DArrayShadow"    {SAVE_TOKEN; return TYPE;}
"isampler2D"              {SAVE_TOKEN; return TYPE;}
"isampler3D"              {SAVE_TOKEN; return TYPE;}
"isamplerCube"            {SAVE_TOKEN; return TYPE;}
"isampler2DArray"         {SAVE_TOKEN; return TYPE;}
"usampler2D"              {SAVE_TOKEN; return TYPE;}
"usampler3D"              {SAVE_TOKEN; return TYPE;}
"usamplerCube"            {SAVE_TOKEN; return TYPE;}
"usampler2DArray"         {SAVE_TOKEN; return TYPE;}
"isampler2DRect"          {SAVE_TOKEN; return TYPE;}
"usampler2DRect"          {SAVE_TOKEN; return TYPE;}
"isamplerBuffer"          {SAVE_TOKEN; return TYPE;}
"usamplerBuffer"          {SAVE_TOKEN; return TYPE;}
"sampler1D"               {SAVE_TOKEN; return TYPE;}
"sampler1DShadow"         {SAVE_TOKEN; return TYPE;}
"sampler3D"               {SAVE_TOKEN; return TYPE;}
"sampler2DShadow"         {SAVE_TOKEN; return TYPE;}
"sampler2DRect"           {SAVE_TOKEN; return TYPE;}
"sampler2DRectShadow"     {SAVE_TOKEN; return TYPE;}
"sampler1DArray"          {SAVE_TOKEN; return TYPE;}
"long"                    {SAVE_TOKEN; return TYPE;}
"short"                   {SAVE_TOKEN; return TYPE;}
"fvec2"                   {SAVE_TOKEN; return TYPE;}
"fvec3"                   {SAVE_TOKEN; return TYPE;}
"fvec4"                   {SAVE_TOKEN; return TYPE;}

"if"                      {return IF;}
"else"                    {return ELSE;}
"while"                   {return WHILE;}

[a-zA-Z_][a-zA-Z0-9_]*    {SAVE_TOKEN; return ID;}             //Identifier
[0-9]+                    {SAVE_TOKEN; return INT;}            //Integer
[0-9]+\.[0-9]*            {SAVE_TOKEN; return FLOAT;}          //Float
"("                       {return OPEN_BRACE;}     //open brace
")"                       {return CLOSE_BRACE;}    //close brace
"{"                       {return OPEN_CBRACE;}    //open curly brackets
"}"                       {return CLOSE_CBRACE;}
";"                       {return SEMICOLON;}
"="                       {return EQL;}
","                       {return COMMA;}
"+"                       {return PLUS;}
"-"                       {return MINUS;}
"*"                       {return MULTIPLY;}
"/"                       {return DEVIDE;}
"!"                       {return NOT;}
"++"                      {return INC;}
"--"                      {return DEC;}
"+="                      {return PLUS_EQL;}
"-="                      {return MINUS_EQL;}
"*="                      {return MULTIPLY_EQL;}
"/="                      {return DEVIDE_EQL;}
"."                       {return DOT;}
[ \t\n]                   ;                        //ignore white-spaces
.                         {return NONE;}           //else return None Token
%%

int yywrap(void){
  return 1;
}
